#include <stdio.h>
#include <stdlib.h> // for atof()
#include "calculator.h"

#define MAXOP 100
#define NUMBER '0'

extern int getop(char s[]);
extern void push(double val);
extern double pop(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type) {

			case '0':
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
   				break;
   			case '*':
				push(pop() * pop());
   				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
          		break;
          	case '\n':
				printf("\t%.8g\n", pop());
          		break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}	
	return 0;

}