#include <stdio.h>
int main()
{
	fibonacci(15);
}
void fibonacci(int n)
{
	int a = 0;
	int b = 1;
	int i;
	for (i = 0;i < n ;i++ )
	{
		printf("%d ", a);
		a = a + b;
		b = a - b;
	}
}