/**
	输入数量不确定的[0,9]范围内的整数，统计每一种数字出现的次数 
*/
#include <stdio.h>
#include <math.h>
int main() {
	const int SIZE = 10;
	int arr[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		arr[i] = 0;
	}
	int x;
	printf("请输入:");
	scanf("%d", &x);
	while (x != -1) {
		arr[x]++;
		printf("请输入:");
		scanf("%d", &x);
	}
	for (i = 0; i < SIZE; i++) {
		printf("%d出现了%d次\n", i, arr[i]);
	}
	return 0;
}

