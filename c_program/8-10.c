/*
习题8-10 输出学生成绩 （20 分）
本题要求编写程序，根据输入学生的成绩，统计并输出学生的平均成绩、最高成绩和最低成绩。建议使用动态内存分配来实现。

输入格式：
输入第一行首先给出一个正整数N，表示学生的个数。接下来一行给出N个学生的成绩，数字间以空格分隔。

输出格式：
按照以下格式输出：

average = 平均成绩
max = 最高成绩
min = 最低成绩
结果均保留两位小数。

输入样例：
3
85 90 95
输出样例：
average = 90.00
max = 95.00
min = 85.00
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	double max = 0;
	double min = 0;
	double avg;
	double sum = 0;

	int n;
	scanf("%d", &n);
	double *p = (double*)malloc(n*sizeof(double));
	int i;
	for (i = 0; i < n; i++) {
		scanf("%lf", p++);
	}
	max = min = *--p;
	int j;
	for (j = 0; j < n; j++) {
		int score = *p--;
		sum += score;
		if (max < score) {
			max = score;
		}
		if (min > score) {
			min = score;
		}
	}
	printf("average = %.2f\n", sum / n);
	printf("max = %.2f\n", max);
	printf("min = %.2f", min);
	free(p);
	return 0;
}

