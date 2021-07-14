#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int mylen(const char *p);
int main() {
	char line[] = "Hello";
	printf("strlen(line)=%d\n", strlen(line));
	printf("sizeof(line)=%d\n", sizeof(line));
	printf("mylen(line)=%d\n", mylen(line));
	return 0;
}
int mylen(const char *p) {
	// 数组遍历 
	int idx = 0;
	int len1 = 0;
	while (p[idx++] != '\0') {
		len1++;
	}
	
	// 指针遍历 
	int len2 = 0;
	while (*p++ != '\0') {
		len2++;
	}
	
	int len = -1;
	if (len1 == len2)
		len = len1;
		
	return len;
}
