#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "Common.h"
void qSort(int *a, int left, int right);
int main() {
	int *a = createArray(SIZE);
	printArray(a, SIZE);
	sort(a, SIZE);
	printArray(a, SIZE);
	return 0;
}
void sort(int *a, int size) {
	qSort(a, 0, size - 1);
}
void qSort(int *a, int left, int right) {
	if (left >= right) {
		return;
	}
	int i, j, temp;
	temp = a[left];
	i = left;
	j = right;
	while (i != j) {
		while (a[j] >= temp && i < j) {
			j--;
		}
		while (a[i] <= temp && i < j) {
			i++;
		}
		if (i < j) {
			swap(&a[i], &a[j]);
		}
	}
	a[left] = a[i];
	a[i] = temp;
	qSort(a, left, i);
	qSort(a, i + 1, right);
}
