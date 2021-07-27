#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Stack {
	ElemType *arr;
	int top;
	int max_size;
} *Stack;

Stack create(int max_size) {
	Stack s = (Stack) malloc(sizeof(struct Stack));
	s->arr = (ElemType*) malloc(sizeof(ElemType) * max_size);
	s->top = -1;
	s->max_size = max_size;
	return s;
}

int stack_empty(Stack s) {
	return s->top < 0;
}

int stack_full(Stack s) {
	return s->top + 1 == s->max_size;
}

void push(Stack s, ElemType e) {
	if (!stack_full(s))
		s->arr[++s->top] = e;
	else
		printf("stack is full!\n");
}

ElemType pop(Stack s) {
	ElemType result = NULL;
	if (!stack_empty(s))
		result = s->arr[s->top--];
	else
		printf("pop stack is empty!\n");
	return result;
}

ElemType peek(Stack s) {
	ElemType result = NULL;
	if (!stack_empty(s))
		result = s->arr[s->top];
	else
		printf("peek stack is empty!\n");
	return result;
}

int recursion(int n, int x) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2 * x;
	else
		return 2 * x * recursion(n - 1, x) - 2 * n * recursion(n - 2, x);
}

int loop(int n, int x) {
	int i, result, parent, ancestor;

	i = 0, result = 0;
	while (i <= n) {
		if (i == 0) {
			parent = 1;
			ancestor = 1;
		} else if (i == 1) {
			parent = 2 * x;
			ancestor = 1;
		} else {
			int ancestor_temp = ancestor;
			ancestor = parent;
			parent = 2 * x * parent - 2 * i * ancestor_temp;
		}
		result = parent;
		i++;
	}

	return result;
}

int by_stack(int n, int x) {
	Stack s = create(n);
	int i;
	for (i = 0; i <= n; i++) {
		if (i == 0)
			push(s, 1);
		else if (i == 1)
			push(s, 2 * x);
		else {
			int parent = pop(s);
			int ancestor = pop(s);
			int current = 2 * x * parent - 2 * i * ancestor;
			push(s, parent);
			push(s, current);
		}
	}
	return pop(s);
}

int main() {
	int n, x;
	printf("type n:");
	scanf("%d", &n);
	printf("type x:");
	scanf("%d", &x);
	printf("recursion:%d\n", recursion(n, x));
	printf("loop:%d\n", loop(n, x));
	printf("by_stack:%d\n", by_stack(n, x));
	return 0;
}











