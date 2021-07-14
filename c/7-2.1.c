/*
练习7-2 求最大值及其下标 （20 分）
本题要求编写程序，找出给定的n个数中的最大值及其对应的最小下标（下标从0开始）。

输入格式:
输入在第一行中给出一个正整数n（1<n≤10）。第二行输入n个整数，用空格分开。

输出格式:
在一行中输出最大值及最大值的最小下标，中间用一个空格分开。

输入样例:
6
2 8 10 1 9 10
输出样例:
10 2
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int i;
	int max = NULL;
	int idx = -1;
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (max == NULL) {
			max = x;
		}
		if (idx == -1) {
			idx = i;
		}
		if (max < x) {
			max = x;
			idx = i;
		}
	}
	printf("%d %d", max, idx);
	return 0;
}

