#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Queue {
	ElemType *arr;
	int front, rear;
	int tag;
	int max_size;
} *Queue;

Queue init(int max_size) {
	Queue q = (Queue) malloc(sizeof(struct Queue));
	q->arr = (ElemType*) malloc(sizeof(ElemType) * max_size);
	q->front = q->rear = 0;
	q->max_size = max_size;
	q->tag = 0;
	return q;
}

int is_empty(Queue q) {
	return q->front == q->rear && q->tag == 0;
}

int is_full(Queue q) {
	return q->front == q->rear && q->tag == 1;
}

void enqueue(Queue q, ElemType data) {
	if (!is_full(q)) {
		q->arr[q->rear] = data;
		q->rear = (q->rear + 1) % q->max_size;
		q->tag = 1;
	} else {
		printf("queue is full!\n");
	}
}

ElemType dequeue(Queue q) {
	ElemType result = -1;
	if (!is_empty(q)) {
		result = q->arr[q->front];
		q->front = (q->front + 1) % q->max_size;
		q->tag = 0;
	} else {
		printf("queue is empty!\n");
	}
	return result;
}

int main() {
	int size = 10;
	Queue q = init(size);

	int i;
	for (i = 0; i < 9; i++)
		enqueue(q, i);

	printf("is_full:%d\n", is_full(q));

	return 0;
}









