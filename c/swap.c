#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void swap(int *a, int *b);
int main() {
	int a = 3;
	int b = 4;
	swap(&a, &b);
	printf("a=%d,b=%d\n", a, b);
	
	int list[7];
	int i, j;
	for (i = 0; i < 7; i++) {
		list[i] = rand() % 100;
		printf("%d ", list[i]);
	}
	
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (list[i] < list[j]) {
				swap(&list[i], &list[j]);
			}
		}
	}
	
	printf("\n");
	
	for (i = 0; i < 7; i++) {
		printf("%d ", list[i]);
	}
	return 0;
}
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
