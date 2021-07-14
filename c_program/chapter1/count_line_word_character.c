#include <stdio.h>

#define IN 0
#define OUT 1

int main()
{
	int c;
	int nc, nw, nl;
	int state;

	nc = nw = nl = 0;
	state = IN;
	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
			nl++;
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			nw++;
		}
	}

	printf("character:%d\tword:%3d\tline:%3d\n", nc, nw, nl);
}