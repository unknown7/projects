/*
ϰ��7-5 �Ұ��� ��20 �֣�
һ������Ԫ�صġ����㡱��ָ��λ���ϵ�Ԫ��ֵ�ڸ���������ڸ�������С��

����Ҫ���д������һ��������n�׷���İ��㡣

�����ʽ��
�����һ�и���һ��������n��1��n��6�������n�У�ÿ�и���n������������Կո�ָ���

�����ʽ��
�����һ���а��ա����±� ���±ꡱ���±��0��ʼ���ĸ�ʽ��������λ�á�������㲻���ڣ��������NONE������Ŀ��֤�����ľ����������һ�����㡣

��������1��
4
1 7 4 1
4 8 3 6
1 6 1 2
0 7 8 9
�������1��
2 1
��������2��
2
1 7
4 1
�������2��
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

