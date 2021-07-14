#include <stdio.h>
int main() {
	int x = 1956;
	int t = x;
	int m = 1;
	while (t > 9) {
		t /= 10;
		m *= 10;
	}
	while (m > 0) {
		int d = x / m;
		printf("%d ", d);
		x %= m;
		m /= 10;
	}
	
	return 0;
}

