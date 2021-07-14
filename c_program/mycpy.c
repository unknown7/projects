#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char* mycpy(char *des, const char *src);
int main() {
	char a[] = "abc";
	char b[] = "cba";
	printf("strcpy=%s\n", strcpy(b, a));
	printf("mycpy=%s\n", mycpy(b, a));
	return 0;
}
char* mycpy(char *des, const char *src) {
	while (*src != '\0') {
		*des++ = *src++;
	}
	*des++ = '\0';
	return des;
}
