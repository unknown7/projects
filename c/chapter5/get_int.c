
#include "get_int_interface.h"

int main()
{
	int i, n;
	i = 0, n = 10;
	int arr[n];

	
	for (; i < n; i++)
		getint(&arr[i]);

	for (i = 0; i < n; i++)
		printf("%d\t", arr[i]);

	return 0;
}

int getint(int *p)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-' ? -1 : 1);
	if (!isdigit(c))
		c = getch();
	for (*p = 0; isdigit(c); c = getch())
		*p = (*p) * 10 + (c - '0');
	(*p) *= sign;
	printf("*p=%d\n", *p);
	if (c != EOF)
		ungetch(c);
	return c;
}





