#include <stdio.h>

#define SIZE 10

int main()
{
	int arr[SIZE], nwhite, nother, c;
	nwhite = nother = 0;
	int i;
	for (i = 0; i < SIZE; ++i)
	{
		arr[i] = 0;
	}

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++arr[c - '0'];
		else if (c == ' ' || c == '\t' || c == '\n')
			nwhite++;
		else
			nother++;

	printf("arr:");
	for (i = 0; i < SIZE; ++i)
	{
		printf(" %d", arr[i]);
	}
	printf(",nwhite:%d,nother:%d", nwhite, nother);

	return 0;
}