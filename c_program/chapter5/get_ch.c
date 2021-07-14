
#include "get_int_interface.h"

#define SIZE 100

static char buff[SIZE];
static int idx = 0;

char getch()
{
	return idx > 0 ? buff[--idx] : getchar();
}

void ungetch(char c)
{
	if (idx == SIZE)
		printf("buff is full");
	else
		buff[idx++] = c;
}