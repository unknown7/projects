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
	int i, j, t;
	for (i = 1; i < n; i++) {
		t = a[i];
		for (j = i; j > 0 && a[j-1] > t; j--) {
			a[j] = a[j-1];
		}
		a[j] = t;
	}
}
