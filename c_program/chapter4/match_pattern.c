#include <stdio.h>
#define MAX 100

int get_line(char a[]);
int str_index(char a[], char pattern[]);

int main()
{
	int c, found;
	char line[MAX], pattern[] = "ould";

	found = 0;

	while (get_line(line) > 1) {
		if (str_index(line, pattern) > 0) {
			printf("%s\n", line);
			found++;	
		}	
	}

	printf("found:%d\n", found);
	return 0;
}

int get_line(char a[]) {
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF) {
		a[i++] = c;
		if (c == '\n')
			break;
	}
	a[i++] = '\0';

	return i;
}

int str_index(char a[], char p[]) {
	int i, j;
	i = j = 0;
	for (; a[i] != '\0' && p[j] != '\0'; i++)
	{
		if (a[i] == p[j]) {
			j++;
		}
	}

	return p[j] == '\0';
}








