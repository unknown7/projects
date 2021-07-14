#include <stdio.h>
#include <math.h>
int main() {
	int m = 1, n = 500;
	int cnt = 0;
	int sum = 0;
	int is = 1;
	printf("请输入m和n：");
	scanf("%d %d", &m, &n);
	if (m < 1 || m > 500) {
		m = 1;
	}
	if (n < 1 || n > 500) {
		n = 500;
	}
	int i;
	for (i = m + 1; i <= n; i++) {
		int j;
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				is = 0;
				break;
			}
		}
		if (is) {
			printf("%d是素数\n", i);
			cnt++;
			sum += i;
		}
		is = 1;
	}
	printf("sum=%d", sum);
	return 0;
}

