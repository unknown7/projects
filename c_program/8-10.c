/*
ϰ��8-10 ���ѧ���ɼ� ��20 �֣�
����Ҫ���д���򣬸�������ѧ���ĳɼ���ͳ�Ʋ����ѧ����ƽ���ɼ�����߳ɼ�����ͳɼ�������ʹ�ö�̬�ڴ������ʵ�֡�

�����ʽ��
�����һ�����ȸ���һ��������N����ʾѧ���ĸ�����������һ�и���N��ѧ���ĳɼ������ּ��Կո�ָ���

�����ʽ��
�������¸�ʽ�����

average = ƽ���ɼ�
max = ��߳ɼ�
min = ��ͳɼ�
�����������λС����

����������
3
85 90 95
���������
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

