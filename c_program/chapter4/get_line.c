#include <stdio.h>

#define MAX 100



int get_line(char a[])
{
	int c, i;
	i = 0;
	while ((c = getchar()) != EOF && i + 1 < MAX) {
		if (c != '\n')
			a[i++] = c;
		else {
			a[i++] = '\n';
			break;
		}
	}
	a[i++] = '\0';
	return i;
}