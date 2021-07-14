#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void z(int nums, int total);
void d(int nums, int total);
void o(int i, int total);
int main() {
	int h;
	scanf("%d", &h);
	z(h / 2, h);
	int i;
	for (i = 0; i < h; i++) {
		printf("* ");
	}
	printf("\n");
	d(h / 2, h);
	return 0;
}
void z(int nums, int total) {
	int i;
	for (i = 1; i <= nums; i++) {
		o(i, total);
	}
}
void d(int nums, int total) {
	int i;
	for (i = nums; i >= 1; i--) {
		o(i, total);
	}
}
void o(int i, int total) {
	int stars = i * 2 - 1;
	int spaces = total - i * 2 + 1;
	int j;
	for (j = 0; j < spaces; j++) {
		printf(" ");
	}
	int k;
	for (k = 0; k < stars; k++) {
		printf("* ");
	}
	printf("\n");
}





