#include <stdio.h>

/**
 * fahrenheit		celsius
 * 1 					-17
 * 20 					-6
 * 40 					4
 * 60 					15
 * 80 					26
 * 100 					37
 * 120 					48
 * 140 					60
 * 160 					71
 * 180 					82
 * 200 					93
 * 220 					104
 * 240 					115
 * 260 					126
 * 280 					137
 * 300 					148
 * 
 * formula:°C=(5/9)(°F-32)
 */
int main()
{
	float fehrenheit, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fehrenheit = lower;

	while (fehrenheit < upper) {
		celsius = (5.0 / 9.0) * (fehrenheit - 32.0);
		printf("fehrenheit:%3.0f\tcelsius:%7.2f\n", fehrenheit, celsius);
		fehrenheit += step;
	}

	return 0;
}