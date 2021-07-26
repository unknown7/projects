#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Queue {
	ElemType *arr;
	int front, rear;
	int max_size;
} *Queue;

Queue init(int max_size) {
	Queue queue = (Queue) malloc(sizeof(struct Queue));
	queue->arr = (ElemType*) malloc(sizeof(ElemType) * max_size);
	queue->front = queue->rear = 0;
	queue->max_size = max_size;
	return queue;
}

int is_empty(Queue queue) {
	return queue->front == queue->rear;
}

int is_full(Queue queue) {
	return (queue->rear + 1) % queue->max_size == queue->front;
}

ElemType dequeue(Queue queue) {
	ElemType result = -1;
	if (!is_empty(queue)) {
		result = queue->arr[queue->front];
		queue->front = (queue->front + 1) % queue->max_size;
	} else {
		printf("queue is empty!\n");
	}
	return result;
}

void enqueue(Queue queue, ElemType data) {
	if (!is_full(queue)) {
		queue->arr[queue->rear] = data;
		queue->rear = (queue->rear + 1) % queue->max_size;
	} else {
		printf("queue is full!\n");
	}
}

int size(Queue queue) {
	return is_empty(queue) ? 0 : (is_full(queue) ? queue->max_size : (queue->rear - queue->front + queue->max_size) % queue->max_size);
}

int main() {
	int max_size = 6;
	Queue q = init(max_size);

	int i;
	for (i = 0; !is_full(q); i++)
		enqueue(q, i);

	while (!is_empty(q))
		printf("%d ", dequeue(q));

	printf("\n");

	return 0;
}














