#include <stdio.h>
int main() {
	int one, two, five;
	int x = 0;
	printf("要凑的钱（元）：");
	scanf("%d", &x);
	int i, j, q;
	for (i = 0; i < x * 10; i++) {
		for (j = 0; j < x * 10 / 2; j++) {
			for (q = 0; q < x * 10 / 5; q++) {
				if (i * 1 + j * 2 + q * 5 == x * 10) {
					printf("可以用%d个1角 %d个2角 %d个5角，凑成%d元\n", i, j, q, x);
					
					goto out;
				}
			}
		}
	}
	out:
	return 0;
}

