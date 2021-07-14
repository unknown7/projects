#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "Common.h"
void merge(int *a, int *ta, int l, int r, int rightEnd);
void mSort(int *a, int *ta, int left, int right);
int main() {
	int *a = createArray(SIZE);
	printArray(a, SIZE);
	sort(a, SIZE);
	printArray(a, SIZE);
	return 0;
}
void sort(int *a, int n) {
	int *ta = (int*)malloc(sizeof(int)*n);
	if (ta) {
		mSort(a, ta, 0, n - 1);
		free(ta);
	}
}
void mSort(int *a, int *ta, int left, int right) {
	int center;
	if (left < right) {
		center = (left + right) / 2;
		mSort(a, ta, left, center);
		mSort(a, ta, center + 1, right);
		merge(a, ta, left, center + 1, right);
	}
}
void merge(int *a, int *ta, int l, int r, int rightEnd) {
	int i = l;
	int j = r;
	int k = l;
	while (i <= r-1 && j <= rightEnd) {
		if (a[i] <= a[j]) {
			ta[k++] = a[i++];
		} else {
			ta[k++] = a[j++];
		}
	}
	while (i <= r-1) {
		ta[k++] = a[i++];
	}
	while (j <= rightEnd) {
		ta[k++] = a[j++];
	}
	int m;
	for (m = l; m <= rightEnd; m++) {
		a[m] = ta[m];
	}
}
