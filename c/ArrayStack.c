#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayStack.h"
const int BLOCK = 20;
const int MAX_SIZE = 20;
int main() {
	
		//*p++的操作内幕！
		 int *p = (int*)malloc(MAX_SIZE);
		*p++=7;
		printf("p[-1]=%d\n", p[-1]);
		printf("p[0]=%d\n", p[0]);
		printf("p[1]=%d\n", p[1]);
	
	
	ArrayStack s = create();
	int i;
	for (i = 0; i < 30; i++) {
		if (!push(&s, i)) {
			printf("栈满了！\n");
			break;
		}
	}
	while (s.cur > 0) {
		printf("%d ", pop(&s));
	}
	return 0;
}
int push(ArrayStack *s, int x) {
	int ret = 1;
	if (s->cur + 1 >= s->size) {
		if (inflate(s, (s->size/BLOCK+1)*BLOCK-s->size)) {
			doPush(s, x);
		} else {
			ret = 0;
		}
	} else {
		doPush(s, x);
	}
	return ret;
}
int pop(ArrayStack *s) {
	int x = -1;
	if (s->cur < s->size && s->cur >= 0) {
		x = s->array[--s->cur];
	}
	return x;
}
ArrayStack create() {
	ArrayStack stack;
	int *p = (int*)malloc(sizeof(int) * BLOCK);
	stack.array = p;
	stack.size = BLOCK;
	stack.cur = 0;
	return stack;
}
int inflate(ArrayStack *s, int more_size) {
	printf("inflate start...s->size=%d\n", s->size);
	int ret = 1;
	if (s->size + more_size >= MAX_SIZE) {
		ret = 0;
	} else {
		int *p = (int*)malloc(sizeof(int) * (s->size+more_size));
		int i;
		for (i = 0; i < s->cur; i++) {
			*(p+i) = s->array[i];
		}
		free(s->array);
		s->array = p;
		s->size += more_size;
	}
	printf("inflate end...s->size=%d\n", s->size);
	return ret;
}
void doPush(ArrayStack *s, int x) {
	s->array[s->cur++] = x;
}






