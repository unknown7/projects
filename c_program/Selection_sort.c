#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "Common.h"
int main() {
	int *a = createArray(SIZE);
	sort(a, SIZE);
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
void sort(int *a, int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(&a[i], &a[min]);
	}
}
