#include <stdio.h>
int main()
{

	char arr[] = "Hello World";
	char *p = arr;
	printf("%c\n", *p++);
	printf("%c\n", *p);
	p = arr;
	p = "Hello World";

	char *pn = "Hello World";

	return 0;
}