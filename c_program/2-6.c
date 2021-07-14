#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
	float a=10, t=3, s;
	s = 0.5 * a * t * t;
	if(s>100)
		s=100;
	printf("height = %.2f", s);
	return 0;
}

