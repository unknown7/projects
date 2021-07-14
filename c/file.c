#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	FILE *file = fopen("test.txt", "r");
	if (file) {
		char c[65535];
		fscanf(file, "%s", c);
		printf("%s\n", c);
		fclose(file);
	} else {
		printf("无法打开文件！");
	}
	return 0;
}

