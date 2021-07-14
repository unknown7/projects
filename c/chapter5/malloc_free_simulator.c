#include <stdio.h>
#define ALLOCSIZE 10000

static char array[ALLOCSIZE];
static char *p = array;

char alloc(int n)
{
	char result;
	if (p + n < array + ALLOCSIZE)
	{
		result = p;
		p += n;
	}
	else
	{
		result = 0;
	}
	return result;
}

void afree(char *pn)
{
	if (pn > array && pn < array + ALLOCSIZE)
		p = pn;
}