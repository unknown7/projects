#include <stdio.h>

int main()
{
	double sum, atof(char []);
	char line[100];
	int get_line(char line[]);

	sum = 0;
	while(get_line(line) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}