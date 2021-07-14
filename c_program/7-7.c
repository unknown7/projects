/*
练习7-7 矩阵运算 （20 分）
给定一个n×n的方阵，本题要求计算该矩阵除副对角线、最后一列和最后一行以外的所有元素之和。副对角线为从矩阵的右上角至左下角的连线。

输入格式:
输入第一行给出正整数n（1<n≤10）；随后n行，每行给出n个整数，其间以空格分隔。

输出格式:
在一行中给出该矩阵除副对角线、最后一列和最后一行以外的所有元素之和。

输入样例:
4
2 3 4 1
5 6 1 1
7 1 8 1
1 1 1 1
输出样例:
35
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int matrix[n][n];
	int i;
	int sum = 0;
	for (i = 0; i < n; i++) {
		int j;
		for (j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			if (i+j!=n-1 && i != n-1 && j != n-1) {
				sum += x;
			}
		}
	}
	printf("%d", sum);
	return 0;
}

