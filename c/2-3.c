#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	const int NUMS = 7;
	int i;
	for (i = NUMS; i > 0; i--) {
		int j;
		for (j = i; j < NUMS; j++) {
			printf(" ");
		}
		int k;
		for (k = 0; k < i; k++) {
			printf("*");
			if (k == i - 1) {
				printf("\n");
			} else {
				printf(" ");
			}
		}
	}
	return 0;

	
}

