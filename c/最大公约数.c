#include <stdio.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int max = 0;
	int i;
	for (i = 2; i <= a; i++) {
		if (a % i == 0 && i <= b && b % i == 0) {
			max = i;
		}
	}
	printf("最大公约数为%d", max);
	return 0;
}

