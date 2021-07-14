#include <stdio.h>

int power(int base, int n);
int get_num();

int main()
{
	int base, n;
	base = get_num();
	n = get_num();
	printf("%d\n", power(base, n));

	return 0;
}

int power(int base, int n)
{
	int i, p;
	p = 1;
	for (i = 0; i < n; ++i)
		p *= base;
	return p;
}

int get_num()
{
	int c, result;
	result = 0;
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			result = (result * 10 + (c - '0'));
		else
			break;
	}
	return result;
}