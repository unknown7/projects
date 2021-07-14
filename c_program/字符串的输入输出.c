#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[]) {
	int i;
	for(i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	
	char string[8];
	scanf("%3s", string);
	printf("%s", string);
	return 0;
}

