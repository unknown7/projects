#include <stdio.h>
#include <math.h>
int main() {
	int a = 5;
	{
		a = 0;
//		int a = 5;
		printf("a=%d\n", a);
	}
	printf("a=%d\n", a);
	return 0;
}

