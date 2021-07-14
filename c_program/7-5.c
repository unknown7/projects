/*
习题7-5 找鞍点 （20 分）
一个矩阵元素的“鞍点”是指该位置上的元素值在该行上最大、在该列上最小。

本题要求编写程序，求一个给定的n阶方阵的鞍点。

输入格式：
输入第一行给出一个正整数n（1≤n≤6）。随后n行，每行给出n个整数，其间以空格分隔。

输出格式：
输出在一行中按照“行下标 列下标”（下标从0开始）的格式输出鞍点的位置。如果鞍点不存在，则输出“NONE”。题目保证给出的矩阵至多存在一个鞍点。

输入样例1：
4
1 7 4 1
4 8 3 6
1 6 1 2
0 7 8 9
输出样例1：
2 1
输入样例2：
2
1 7
4 1
输出样例2：
NONE
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int x;
	int y;
} Point;
int main() {
	int n;
	scanf("%d", &n);
	int matrix[n][n];
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	
	for (i = 0; i < n; i++) {
		int is = 1;
		int max = matrix[i][0];
		Point p = {i, 0};
		for (j = 0; j < n; j++) {
			if (max <= matrix[i][j]) {
				max = matrix[i][j];
				p.x = i;
				p.y = j;
			}
		}
		for (k = 0; k < n; k++) {
			if (max > matrix[k][p.y]) {
				is = 0;
				break;
			}
		}
		if (is) {
			printf("%d %d", p.x, p.y);
			return 0;
		}
	}
	printf("NONE");
	return 0;
}

