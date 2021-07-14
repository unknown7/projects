#ifndef _Common_H_
#define _Common_H_
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define MODE 1000
void swap(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
int* createArray(int size) {
	int *a = (int*)malloc(size*sizeof(int));
	int i;
	for (i = 0; i < size; i++) {
		a[i] = rand() % MODE;
	}
	return a;
}
void printArray(int *a, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void sort(int *a, int n);
#endif

