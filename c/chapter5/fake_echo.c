#include <stdio.h>

int main(int argc, char const *argv[])
{
	while (--argc > 0)
	{
		printf("%s%s", *++argv, argc > 1 ? " " : "");
	}
	return 0;
}