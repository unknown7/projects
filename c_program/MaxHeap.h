#ifndef _MaxHeap_H_
#define _MaxHeap_H_
#define ElementType int
#define MAX 1000
typedef struct _maxHeap {
	ElementType *array;
	int size;
	int capacity;
} MaxHeap;
MaxHeap createHeap();
int isFull(MaxHeap *h);
int isEmpty(MaxHeap *h);
void insert(MaxHeap *h, ElementType x);
ElementType del(MaxHeap *h);
#endif
