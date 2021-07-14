#include <stdio.h>
int main() {
	int n = 0;
	printf("«Î ‰»În:");
	scanf("%d", &n);
	double sum = 0.0;
	int i;
	for (i = 1; i <= n; i++) {
		sum += 1.0 / i;
	}
	printf("f(%d)1=%f\n", n, sum);
	
	sum = 0.0;
	double sign = 1.0;
	for (i = 1; i <= n; i++) {
		sum += sign / i;
		sign = -sign;
	}
	printf("f(%d)2=%f\n", n, sum);
	return 0;
}

