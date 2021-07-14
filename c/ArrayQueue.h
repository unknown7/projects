#ifndef _ArrayQueue_H_
#define _ArrayQueue_H_
typedef struct {
	int *array;
	int front;
	int rear;
	int size;
} ArrayQueue;
ArrayQueue create(int size);
int addQ(ArrayQueue *q, int x);
int deleteQ(ArrayQueue *q);
int isEmpty(ArrayQueue *q);
int isFull(ArrayQueue *q);
#endif
