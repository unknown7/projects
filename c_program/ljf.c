#include <stdio.h>

int main() {
	int m, n;
	int i;
	int cnt = 0;
	int sum = 0;
	scanf("%d %d", &m, &n);
	for (i = m; i <= n; i++) {
		int isPrime = 1;
		int k;
		for (k = 2; k < i-1; k++) {
			if (i % k == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			printf("%d������\n", i);
			cnt++;
		}
	}
	printf("%d��%d�ڹ���%d������", m, n, cnt);
	return 0;
}
