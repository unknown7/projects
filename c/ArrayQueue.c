#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayQueue.h"
int main() {
	ArrayQueue q = create(7);
	while (addQ(&q, rand() % 100));
	int x;
	while ((x = deleteQ(&q)) != EOF) {
		printf("%d ", x);
	}
	return 0;
}
ArrayQueue create(int size) {
	ArrayQueue q;
	q.front = q.rear = 0;
	q.size = size;
	int *p = (int*)malloc(sizeof(int) * q.size);
	q.array = p;
	return q;
}
int addQ(ArrayQueue *q, int x) {
	int ret = 1;
	if (isFull(q)) {
		printf("Õ»ÂúÁË£¡\n");
		ret = 0;
	} else {
		q->array[(q->front++) % q->size] = x;
	}
	return ret;
}
int deleteQ(ArrayQueue *q) {
	int x;
	if (!isEmpty(q)) {
		x = q->array[q->rear++];
	} else {
		printf("Õ»¿ÕÁË£¡\n");
		x = EOF;
	}
	return x;
}
int isEmpty(ArrayQueue *q) {
	return q->front == q->rear;
}
int isFull(ArrayQueue *q) {
	return (q->front + 1) % q->size == q->rear;
}
