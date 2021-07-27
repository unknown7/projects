#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
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

static char pairs[3][2] = {
	{'(', ')'},
	{'[', ']'},
	{'{', '}'},
};
int is_pair(char a, char b) {
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			if (pairs[i][j] == a)
				return pairs[i][(j + 1) % 2] == b;
	return 0;
}

int main() {
	printf("type brackets:");
	char *input, c;
	scanf("%s", input);
	Stack s = create(10000);
	push(s, *input++);
	while (*input != '\0') {
		if (!stack_empty(s) && is_pair((c = *input++), peek(s)))
			pop(s);
		else
			push(s, c);
	}

	while (!stack_empty(s))
		printf("%c ", pop(s));
	printf("\n");
	return 0;
}















