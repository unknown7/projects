/*
习题8-7 字符串排序 （20 分）
本题要求编写程序，读入5个字符串，按由小到大的顺序输出。

输入格式：
输入为由空格分隔的5个非空字符串，每个字符串不包括空格、制表符、换行符等空白字符，长度小于80。

输出格式：
按照以下格式输出排序后的结果：

After sorted:
每行一个字符串
输入样例：
red yellow blue green white
输出样例：
After sorted:
blue
green
red
white
yellow
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	const int SIZE = 5;
	char c[SIZE][80];
	char *p[SIZE];
	int i, j;
	for (i = 0; i < SIZE; i++) {
		scanf("%79s", c[i]);
		p[i] = c[i];
	}
	for (i = 0; i < SIZE; i++) {
		for (j = i; j < SIZE; j++) {
			if (strcmp(p[i], p[j]) > 0) {
				char *t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	printf("After sorted:\n");
	for (i = 0; i < SIZE; i++) {
		printf("%s\n", p[i]);
	}
	
	return 0;
}

