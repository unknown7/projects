/*
ϰ��4-8 �߿�׹�� ��20 �֣�
Ƥ���ĳ�����߶��������£����غ󷴵���ԭ�߶ȵ�һ�룬�����£��ٷ�������������˷�������Ƥ���ڵ�n�����ʱ���ڿ���һ���������پ��룿��n�η����ĸ߶��Ƕ��٣�

�����ʽ:
������һ���и��������Ǹ��������ֱ���Ƥ��ĳ�ʼ�߶Ⱥ�n�����ڳ����ͷ�Χ�ڡ�

�����ʽ:
��һ����˳�����Ƥ���n�����ʱ�ڿ��о����ľ��롢�Լ���n�η����ĸ߶ȣ������һ���ո�ָ�������һλС������Ŀ��֤������������˫���ȷ�Χ��

��������:
33 5
�������:
94.9 1.0
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	double h, n;
	double distance = 0, lastHeight = 0;
	scanf("%lf %lf", &h, &n);
	int i;
	for (i = 0; i < n; i++) {
		if (i < n-1) {
			distance += (h+h/2);
		} else {
			distance += h;
			lastHeight = h / 2;
		}
		h = h / 2;
	}
	printf("%.1f %.1f", distance, lastHeight);
	return 0;
}

