/*
ϰ��6-7 �򵥼����� ��20 �֣�
ģ����������Ĺ��������������ֻ�ܽ��мӼ��˳����㣬�������ͽ��������������������������ȼ���ͬ���������ҵ�˳����㡣

�����ʽ:
������һ���и���һ������������ʽ��û�пո���������һ�������������Ⱥš�=��˵�����������

�����ʽ:
��һ���������ʽ�����������������������ĸΪ0���зǷ�������������������Ϣ��ERROR����

��������:
1+2*10-10/2=
�������:
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
