#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = 17185;
	printf("%x\n", i);
	printf("%p\n", &i);

	int* p = &i;
	printf("%p\n", p);

	return 0;
}