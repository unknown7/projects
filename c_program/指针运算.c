#include <stdio.h>
#include <math.h>
int main() {
	char ac[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,};
	char *p = ac;
	printf("p=%p\n", p);
	printf("p+1=%p\n", p+1);
	printf("ac=%p\n", ac);
	printf("*p=%d\n", *p);
	printf("*(p+1)=%d\n", *(p+1));
	
	
	int ai[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,};
	int *q = ai;
	printf("q=%p\n", q);
	printf("q+1=%p\n", q+1);
	printf("ai=%p\n", ai);
	printf("*q=%d\n", *q);
	printf("*(q+1)=%d\n", *(q+1));
	return 0;
}

