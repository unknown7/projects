#include <stdio.h>
#include <math.h>
int main() {
	int ai[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1,};
	int *p = ai;
	while (*p != -1) {
		printf("%d ", *p++);
	}
}

