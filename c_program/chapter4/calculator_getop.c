#include <ctype.h>
#include <stdio.h>
#include "calculator.h"


int getop(char s[])
{
	int getch(void);
	void ungetch(int c);
	int i, c;
	i = 0;
	while ((s[i] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return '0';
}