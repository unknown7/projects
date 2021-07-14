#include <stdio.h>
#include <math.h>
int cal(int s, int e);

int main() {
	int s = 10;
	int e = 25;
	int result = cal(s, e);
	printf("sum=%d", result);
	return 0;
}

int cal(int s, int e) {
	int sum = 0;
	for (; s <= e; s++) {
		sum += s;
	}
	return sum;
}
