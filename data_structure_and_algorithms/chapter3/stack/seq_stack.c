#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int ElemType;

typedef struct {
	ElemType *arr;
	int top;
} Seq_Stack, *Stack;

Seq_Stack* init() {
	Seq_Stack *stack = (Seq_Stack *) malloc(sizeof(Seq_Stack));
	(*stack).arr = (ElemType *) malloc(sizeof(ElemType) * MAX_SIZE);
	(*stack).top = -1;
	return stack;
}

int stack_empty(Seq_Stack *stack) {
	return stack == NULL || stack->top < 0;
}

int stack_full(Stack s) {
	return s->top == MAX_SIZE - 1;
}

void push(Stack s, ElemType data) {
	if (!stack_full(s))
		s->arr[++s->top] = data;
	else
		printf("stack is full!\n");
}

ElemType pop(Seq_Stack *s) {
	if (!stack_empty(s)){
		return (*s).arr[s->top--];
	}
	else {
		printf("stack is empty!\n");
		return -1;
	}
}

ElemType peek(Stack s) {
	if (!stack_empty(s)) {
		return (*s).arr[s->top];
	}
	else {
		printf("stack is empty!\n");
		return -1;
	}
}

int main() {
	Seq_Stack *stack = init();
	int i;
	for(i = 0; i < 10; i++)
		push(stack, i);

	printf("%d\n", pop(stack));

	printf("%d\n", peek(stack));

	return 0;
}



















