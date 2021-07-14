#include <stdio.h>
#include "calculator.h"

#define MAX 100
int bf_idx = 0;
int buff[MAX];

int getch(void)
{
	return bf_idx > 0 ? buff[--bf_idx] : getchar();
}

void ungetch(int c)
{
	if (bf_idx >= MAX)
		printf("buff out of size!\n");
	else
		buff[++bf_idx] = c;
}