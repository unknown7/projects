#include <stdio.h>

int test(int c);

int main()
{
	int c;

	c = getchar();
	while (test(c)) {
		putchar(c);
		c = getchar();
	}
}

int test(int c)
{
	printf("test..");
	return (c != EOF);
}