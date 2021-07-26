#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef char ElemType;

typedef struct {
	ElemType *arr;
	int top;
} Seq_Stack, *Stack;

typedef struct Node {
	char data;
	struct Node *next;
} *Node;

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

	char input[MAX_SIZE];
	printf("input please:");
	scanf("%s", input);

	char *arr = input;
	Node first = NULL, prior = NULL;
	while (*arr != '\0') {
		Node node = (Node) malloc(sizeof(Node));
		node->data = *arr++;
		if (first == NULL)
			first = node;
		if (prior != NULL)
			prior->next = node;
		prior = node;
	}

	Seq_Stack *stack = init();
	Node node = first;
	while (node != NULL) {
		push(stack, node->data);
		node = node->next;
	}

	node = first;
	while (!stack_empty(stack) && pop(stack) == node->data)
		node = node->next;

	printf(!stack_empty(stack) ? "%s is NOT central symmetrical\n" : "%s is central symmetrical\n", input);

	return 0;
}



















