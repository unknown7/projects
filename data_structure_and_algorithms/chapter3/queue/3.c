#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node *next;
} *Node;

typedef struct Stack {
	Node head;
} *Stack;

typedef struct Queue {
	ElemType *arr;
	int front, rear;
	int max_size;
} *Queue;

Stack create_stack() {
	Stack s = (Stack) malloc(sizeof(struct Stack));
	Node head = (Node) malloc(sizeof(struct Node));
	s->head = head;
	return s;
}

Queue create_queue(int max_size) {
	Queue q = (Queue) malloc(sizeof(struct Queue));
	q->arr = (ElemType*) malloc(sizeof(ElemType));
	q->front = q->rear = 0;
	q->max_size = max_size;
	return q;
}

int stack_empty(Stack s) {
	return s->head->next == NULL;
}

int queue_empty(Queue q) {
	return q->front == q->rear;
}

int queue_full(Queue q) {
	return (q->rear + 1) % q->max_size == q->front;
}

void push(Stack s, ElemType data) {
	Node node = (Node) malloc(sizeof(struct Node));
	node->data = data;
	node->next = s->head->next;
	s->head->next = node;
}

ElemType pop(Stack s) {
	ElemType result = -1;
	if (!stack_empty(s)) {
		Node top = s->head->next;
		result = top->data;
		s->head->next = top->next;
		free(top);
	} else {
		printf("stack is empty!\n");
	}
	return result;
}

ElemType peek(Stack s) {
	ElemType result = -1;
	if (!stack_empty(s)) {
		result = s->head->next->data;		
	} else {
		printf("stack is empty!\n");
	}
	return result;
}

void enqueue(Queue q, ElemType data) {
	if (!queue_full(q)) {
		q->arr[q->rear] = data;
		q->rear = (q->rear + 1) % q->max_size;
	} else {
		printf("queue is full!\n");
	}
}

ElemType dequeue(Queue q) {
	ElemType result = -1;
	if (!queue_empty(q)) {
		result = q->arr[q->front];
		q->front = (q->front + 1) % q->max_size;
	} else {
		printf("queue is empty!\n");
	}
	return result;
}

void enqueue_by_stack(Stack s1, Stack s2, ElemType data) {
	push(s1, data);
}

ElemType dequeue_by_stack(Stack s1, Stack s2) {
	if (stack_empty(s2)) {
		while (!stack_empty(s1))
			push(s2, pop(s1));
	}

	ElemType result = -1;
	if (!stack_empty(s2)) {
		result = pop(s2);
	} else {
		printf("empty!\n");
	}

	return result;
}

int queue_empty_by_stack(Stack s1, Stack s2) {
	return stack_empty(s1) && stack_empty(s2);
}

int main() {

	Stack s1 = create_stack();
	Stack s2 = create_stack();

	int i;
	for (i = 0; i < 10; i++)
		enqueue_by_stack(s1, s2, i);

	while (!queue_empty_by_stack(s1, s2))
		printf("%d ", dequeue_by_stack(s1, s2));

	printf("\n");

	return 0;
}






























