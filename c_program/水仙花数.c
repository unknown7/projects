#include <stdio.h>
#include <math.h>
int main() {
	int n;
//	printf("«Î ‰»Î£∫");
	scanf("%d", &n);
	int m = 1;
	int i;
	int cnt = 0;
	for (i = 0; i < n; i++) {
		m *= 10;
		cnt++;
	}
	int w = m / 10;
	int x;
	for (x = m / 10; x < m; x++) {
		int t = w;
		int q = x;
		double sum = 0;
		while (t > 0) {
			int a = q / t;
			sum += pow(a, cnt);
			q %= t;
			t /= 10;
		}
		if (sum == x) {
			printf("%d\n", x);
		}
	}
	
	return 0;
}

