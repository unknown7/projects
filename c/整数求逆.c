#include <stdio.h>
int main() {
	int x = 0;
	printf("ÇëÊäÈë£º");
	scanf("%d", &x);
	int digit = 0;
	int ret = 0;
	while (x > 0) {
		digit = x % 10;
		ret = ret * 10 + digit;
		x /= 10;
	}
	printf("ret = %d", ret);
	return 0;
}
