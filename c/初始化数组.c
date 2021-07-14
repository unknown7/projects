#include <stdio.h>
#include <math.h>
int main() {
	int arr1[10] = {2, [5] = 6};
	const int SIZE1 = sizeof(arr1) / sizeof(arr1[0]);
	printf("sizeof(arr1)=%d\n", SIZE1);
	int i;
	for (i = 0; i < SIZE1; i++) {
		printf("arr1[%d]=%d\n", i, arr1[i]);
	}

	int arr2[10] = {[0]=3,6,[4]=7};
	const int SIZE2 = sizeof(arr2) / sizeof(arr2[0]);
	printf("sizeof(arr2)=%d\n", SIZE2);
	int j;
	for (j = 0; j < SIZE2; j++) {
		printf("arr2[%d]=%d\n", j, arr2[j]);
	}
	
	return 0;
}
