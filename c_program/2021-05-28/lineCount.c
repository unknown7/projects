#include <stdio.h>

int main()
{
	long nl;
	int c;
	nl = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			nl++;
		}
	}
	printf("%ld\n", nl);
}