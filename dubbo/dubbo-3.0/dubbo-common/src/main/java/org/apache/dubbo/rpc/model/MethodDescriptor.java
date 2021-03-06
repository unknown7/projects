/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.apache.dubbo.rpc.model;

import org.apache.dubbo.common.constants.CommonConstants;
import org.apache.dubbo.common.logger.Logger;
import org.apache.dubbo.common.logger.LoggerFactory;
import org.apache.dubbo.common.stream.StreamObserver;
import org.apache.dubbo.common.utils.ReflectUtils;

import java.lang.reflect.Method;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;
import java.util.stream.Stream;

import static org.apache.dubbo.common.constants.CommonConstants.$ECHO;
import static org.apache.dubbo.common.constants.CommonConstants.$INVOKE;
import static org.apache.dubbo.common.constants.CommonConstants.$INVOKE_ASYNC;
import static org.apache.dubbo.common.constants.CommonConstants.PROTOBUF_MESSAGE_CLASS_NAME;

public class MethodDescriptor {

    private static final String GRPC_ASYNC_RETURN_CLASS = "com.google.common.util.concurrent.ListenableFuture";
    private static final String TRI_ASYNC_RETURN_CLASS = "java.util.concurrent.CompletableFuture";
    private static final String REACTOR_RETURN_CLASS = "reactor.core.publisher.Mono";
    private static final String RX_RETURN_CLASS = "io.reactivex.Single";
    private static final String GRPC_STREAM_CLASS = "io.grpc.stub.StreamObserver";

    private static final Logger logger = LoggerFactory.getLogger(MethodDescriptor.class);
    protected final String methodName;
    private final Method method;
    private final String paramDesc;
    /**
     * duplicate filed as paramDesc, but with different format.
     */
    private final String[] compatibleParamSignatures;
    private final Class<?>[] parameterClasses;
    private final Class<?> returnClass;
    private final Type[] returnTypes;
    private final boolean generic;
    private final boolean wrap;
    private final ConcurrentMap<String, Object> attributeMap = new ConcurrentHashMap<>();

    public MethodDescriptor(Method method) {
        this(method, method.getParameterTypes(), method.getReturnType());
    }

    public MethodDescriptor(Method method, Class<?>[] parameterClasses, Class<?> returnClass) {
        this.method = method;
        this.methodName = method.getName();
        this.parameterClasses = parameterClasses;
        this.returnClass = returnClass;
        Type[] returnTypesResult;
        try {
            returnTypesResult = ReflectUtils.getReturnTypes(method);
        } catch (Throwable throwable) {
            logger.error("fail to get return types. Method name: " + methodName + " Declaring class:" + method.getDeclaringClass().getName(), throwable);
            returnTypesResult = new Type[]{returnClass, returnClass};
        }
        this.returnTypes = returnTypesResult;
        this.wrap = needWrap();
        this.paramDesc = ReflectUtils.getDesc(parameterClasses);
        this.compatibleParamSignatures = Stream.of(parameterClasses)
            .map(Class::getName)
            .toArray(String[]::new);
        this.generic = (methodName.equals($INVOKE) || methodName.equals($INVOKE_ASYNC)) && parameterClasses.length == 3;
    }

    private static boolean isStreamType(Class<?> clz) {
        return StreamObserver.class.isAssignableFrom(clz) || GRPC_STREAM_CLASS.equalsIgnoreCase(clz.getName());
    }

    public boolean isNeedWrap() {
        return wrap;
    }

    /**
     * Determine if the request and response instance should be wrapped in Protobuf wrapper object
     *
     * @return true if the request and response object is not generated by protobuf
     */
    protected boolean needWrap() {
        // generic call must be wrapped
        if (CommonConstants.$INVOKE.equals(methodName) || CommonConstants.$INVOKE_ASYNC.equals(methodName)) {
            return true;
        }
        // echo must be wrapped
        if ($ECHO.equals(methodName)) {
            return true;
        }
        int protobufParameterCount = 0;
        int javaParameterCount = 0;
        for (Class<?> parameterClass : parameterClasses) {
            if (isStreamType(parameterClass)) {
                // more than one stream param
                throw new IllegalStateException("method params error: more than one Stream params. method=" + methodName);
            }
            if (isProtobufClass(parameterClass)) {
                protobufParameterCount++;
            } else {
                javaParameterCount++;
            }
            if (protobufParameterCount > 0 && javaParameterCount > 0) {
                throw new IllegalStateException("Bad method type, can not mix protobuf and normal pojo");
            }
        }
        // protobuf only support one param
        if (protobufParameterCount >= 2) {
            throw new IllegalStateException("method params error: more than one protobuf params. method=" + methodName);
        }

        boolean returnClassProtobuf = isProtobufClass(returnClass);
        if (protobufParameterCount > 0 && returnClassProtobuf) {
            return false;
        }
        // handler reactor or rxjava only consider gen by proto
        if (isMono(returnClass) || isRx(returnClass)) {
            return false;
        }
        if (protobufParameterCount <= 0 && !returnClassProtobuf) {
            return true;
        }
        // handle grpc stub only consider gen by proto
        if (GRPC_ASYNC_RETURN_CLASS.equalsIgnoreCase(returnClass.getName()) && protobufParameterCount == 1) {
            return false;
        }
        // handle dubbo generated method
        if (TRI_ASYNC_RETURN_CLASS.equalsIgnoreCase(returnClass.getName())) {
            Class<?> actualReturnClass =
                (Class<?>) ((ParameterizedType) method.getGenericReturnType()).getActualTypeArguments()[0];
            boolean actualReturnClassProtobuf = isProtobufClass(actualReturnClass);
            if (actualReturnClassProtobuf && protobufParameterCount == 1) {
                return false;
            }
            if (!actualReturnClassProtobuf && protobufParameterCount == 0) {
                return true;
            }
        }

        // todo remove this in future
        boolean ignore = checkNeedIgnore();
        if (ignore) {
            return protobufParameterCount != 1;
        }
        if (!returnClassProtobuf || javaParameterCount > 0) {
            throw new IllegalStateException("method params error method=" + methodName);
        }
//            throw new IllegalStateException("method params error method=" + methodName);
        // java param should be wrapped
        return javaParameterCount > 0;
    }

    /**
     * fixme will produce error on grpc. but is harmless so ignore now
     */
    private boolean checkNeedIgnore() {
        return Iterator.class.isAssignableFrom(returnClass);
    }

    private boolean isMono(Class<?> clz) {
        return REACTOR_RETURN_CLASS.equalsIgnoreCase(clz.getName());
    }

    private boolean isRx(Class<?> clz) {
        return RX_RETURN_CLASS.equalsIgnoreCase(clz.getName());
    }

    public boolean isProtobufClass(Class<?> clazz) {
        while (clazz != Object.class && clazz != null) {
            Class<?>[] interfaces = clazz.getInterfaces();
            if (interfaces.length > 0) {
                for (Class<?> clazzInterface : interfaces) {
                    if (PROTOBUF_MESSAGE_CLASS_NAME.equalsIgnoreCase(clazzInterface.getName())) {
                        return true;
                    }
                }
            }
            clazz = clazz.getSuperclass();
        }
        return false;
    }

    public boolean matchParams(String params) {
        return paramDesc.equalsIgnoreCase(params);
    }

    public Method getMethod() {
        return method;
    }

    public String getParamDesc() {
        return paramDesc;
    }

    public String[] getCompatibleParamSignatures() {
        return compatibleParamSignatures;
    }

    public Class<?>[] getParameterClasses() {
        return parameterClasses;
    }

    public Class<?> getReturnClass() {
        return returnClass;
    }

    public Type[] getReturnTypes() {
        return returnTypes;
    }

    public String getMethodName() {
        return methodName;
    }

    public boolean isGeneric() {
        return generic;
    }

    public void addAttribute(String key, Object value) {
        this.attributeMap.put(key, value);
    }

    public Object getAttribute(String key) {
        return this.attributeMap.get(key);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        MethodDescriptor that = (MethodDescriptor) o;
        return generic == that.generic
            && wrap == that.wrap
            && Objects.equals(method, that.method)
            && Objects.equals(paramDesc, that.paramDesc)
            && Arrays.equals(compatibleParamSignatures, that.compatibleParamSignatures)
            && Arrays.equals(parameterClasses, that.parameterClasses)
            && Objects.equals(returnClass, that.returnClass)
            && Arrays.equals(returnTypes, that.returnTypes)
            && Objects.equals(methodName, that.methodName)
            && Objects.equals(attributeMap, that.attributeMap);
    }

    @Override
    public int hashCode() {
        int result = Objects.hash(method, paramDesc, returnClass, methodName, generic, wrap, attributeMap);
        result = 31 * result + Arrays.hashCode(compatibleParamSignatures);
        result = 31 * result + Arrays.hashCode(parameterClasses);
        result = 31 * result + Arrays.hashCode(returnTypes);
        return result;
    }
}
