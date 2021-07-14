/*
习题6-7 简单计算器 （20 分）
模拟简单运算器的工作。假设计算器只能进行加减乘除运算，运算数和结果都是整数，四种运算符的优先级相同，按从左到右的顺序计算。

输入格式:
输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。

输出格式:
在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，则输出错误信息“ERROR”。

输入样例:
1+2*10-10/2=
输出样例:
10
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int isNum(char c);
int isOpt(char c);
int main() {
	char c[100];
	scanf("%99s", c);
	char *p = c;
	char s = *p++;
	int numbers[100] = {0};
	int nidx = 0;
	char operators[100] = {0};
	int oidx = 0;
	int num = 1;
	while (s != '=') {
		if (isNum(s)) {
			if (num) {
				numbers[nidx++] = s-48;
				num = !num;
			} else {
				numbers[nidx-1] = numbers[nidx-1]*10 + (s-48);
			}
		} else if (isOpt(s)) {
			if (!num) {
				operators[oidx++] = s;
				num = !num;
			} else {
				printf("ERROR");
				return 0;
			}
		} else {
			printf("ERROR");
			return 0;
		}
		s = *p++;
	}
	if (nidx != oidx + 1) {
		printf("ERROR");
		return 0;
	}
	
	int result = 0;
	int a = numbers[0];
	int b = numbers[1];
	char opt = operators[0];
	switch(opt) {
		case '+':
			result += a + b;
			break;
		case '-':
			result += a - b;
			break;
		case '*':
			result += a * b;
			break;
		case '/':
			if (b == 0) {
				printf("ERROR");
				return 0;
			}
			result += a / b;
			break;
		default:
			result = a;
	}
	
	int i;
	for (i = 2; i < nidx; i++) {
		int x = numbers[i];
		char opt = operators[i-1];
		switch(opt) {
			case '+':
				result += x;
				break;
			case '-':
				result -= x;
				break;
			case '*':
				result *= x;
				break;
			case '/':
				result /= x;
				break;
		}
	}
	printf("%d", result);
	return 0;
}
int isNum(char c) {
	return c >=48 && c <=57;
}
int isOpt(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';  
}
