#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	char c[] = "Hello";
	char *p = strchr(c, 'l');
	char *q = (char*)malloc(sizeof(p) + 1);
	strcpy(q, p);
	printf("q=%s\n", q);
	char t = *p;
	*p = '\0';
	printf("c=%s\n", c);
	*p = t;
	printf("c=%s\n", c);
	return 0;
}

