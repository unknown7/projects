#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "MaxHeap.h"
int main() {
	MaxHeap h = createHeap(50);
	int i;
	for (i = 0; i < 10; i++) {
		insert(&h, rand() % 100);
	}
	while (!isEmpty(&h)) {
		printf("%d ", del(&h));
	}
	return 0;
}
MaxHeap createHeap(int maxSize) {
	MaxHeap heap;
	heap.array = (ElementType*)malloc(sizeof(ElementType)*(maxSize+1));
	heap.capacity = maxSize;
	heap.size = 0;
	heap.array[0] = MAX;
	return heap;
}
int isFull(MaxHeap *h) {
	return h->size == h->capacity;
}
int isEmpty(MaxHeap *h) {
	return h->size == 0;
}
void insert(MaxHeap *h, ElementType x) {
	int i;
	if (isFull(h)) {
		printf("full heap!");
		return;
	}
	for (i = ++h->size; x > h->array[i/2]; i /= 2) {
		h->array[i] = h->array[i/2];
	}
	h->array[i] = x;
}
ElementType del(MaxHeap *h) {
	ElementType ret, x;
	int parent, child;
	if (isEmpty(h)) {
		printf("empty heap!");
		return EOF;
	}
	ret = h->array[1];
	x = h->array[h->size--];
	for (parent = 1; parent*2 <= h->size; parent = child) {
		child = parent * 2;
		if (child < h->size && h->array[child] < h->array[child+1]) {
			child++;
		}
		if (x >= h->array[child]) {
			break;
		}
		h->array[parent] = h->array[child];
	}
	h->array[parent] = x;
	return ret;
}
























