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

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
	float fahrenheit, celsius;

	for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit+=STEP)
	{
		celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
		printf("fahrenheit:%3.0f\tcelsius:%7.2f\n", fahrenheit, celsius);
	}
}