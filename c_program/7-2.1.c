/*
��ϰ7-2 �����ֵ�����±� ��20 �֣�
����Ҫ���д�����ҳ�������n�����е����ֵ�����Ӧ����С�±꣨�±��0��ʼ����

�����ʽ:
�����ڵ�һ���и���һ��������n��1<n��10�����ڶ�������n���������ÿո�ֿ���

�����ʽ:
��һ����������ֵ�����ֵ����С�±꣬�м���һ���ո�ֿ���

��������:
6
2 8 10 1 9 10
�������:
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

