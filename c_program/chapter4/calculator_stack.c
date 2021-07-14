#include <stdio.h>
#include "calculator.h"

#define MAX 100

double arr[MAX];
int idx = 0;

void push(double val)
{
	if (idx >= MAX)
		printf("out of size!\n");
	else
		arr[idx++] = val;
}

double pop(void)
{
	if (idx <= 0) {
		printf("stack is empty!\n");
		return 0.0;
	}
	else
		return arr[--idx];
}