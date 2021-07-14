#include <stdio.h>

#define MAX 100

int get_line(void);
void copy(void);
char line[MAX], longest_line[MAX];

int main()
{
	extern char longest_line[];
	int max, cur;

	max = 0;
	while ((cur = get_line()) > 1)
		if (cur > max) {
			max = cur;
			copy();
		}

	printf("longest:%s\n", longest_line);
	return 0;
}

int get_line(void)
{
	extern char line[];
	int c, i;
	i = 0;
	while ((c = getchar()) != EOF && i + 1 < MAX) {
		if (c != '\n')
			line[i++] = c;
		else {
			line[i++] = '\n';
			break;
		}
	}
	line[i++] = '\0';
	return i;
}

void copy(void)
{
	extern char line[], longest_line[];
	int i;
	i = 0;
	while (line[i] != '\0') {
		longest_line[i] = line[i];
		i++;
	}
}