#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int mycmp(const char *a, const char *b);
int main() {
	char a[] = "abc";
	char b[] = "Abc";
	printf("strcmp=%d\n", strcmp(a, b));
	printf("mycmp=%d", mycmp(a, b));
	return 0;
}
int mycmp(const char *a, const char *b) {
	while (*a == *b && *a != '\0') {
		a++;
		b++;
	}
	return *a - *b;
}
