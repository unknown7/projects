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
	int i, j;
	for (i = n - 1; i >= 0; i--) {
		int flag = 0;
		for (j = 0; j < i; j++) {
			if (a[j] > a[j+1]) {
				swap(&a[j], &a[j+1]);
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
}
