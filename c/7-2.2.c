/*
ϰ��7-2 ��һ�������г������ĸ�λ���� ��20 �֣�
����һ������������ÿ��������ÿһλ���֣�����ִ������ĸ�λ���֡��������3������1234��2345��3456�����г�����������������3��4����������3�Ρ�

�����ʽ��
�����ڵ�1���и���������N����1000�����ڵڶ����и���N�����������ͷ�Χ�ķǸ����������ּ��Կո�ָ���

�����ʽ��
��һ���а���ʽ��M: n1 n2 ...�����������M����������n1��n2������Ϊ���ִ������ĸ�λ���֣�����С�����˳�����С����ּ��Կո�ָ�����ĩβ�����ж���ո�

����������
3
1234 2345 3456
���������
3: 3 4
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int result[10] = {0};
	int i, j;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (j = 0; j < n; j++) {
		int x = arr[j];
		int t1 = x;
		int t2 = x;
		int cnt = 0;
		int divisor = 1;
		while (t1 > 9) {
			cnt++;
			divisor *= 10;
			t1 /= 10;
		}
		while (t2 > 0) {
			result[t2/divisor]++;
			t2 %= divisor;
			if (t2 == 0) {
				result[0] += cnt;
			}
			divisor /= 10;
			cnt--;
		}
	}
	int max = 0;
	for (i = 0; i < 10; i++) {
		if (max < result[i]) {
			max = result[i];
		}
	}
	int numbers[10];
	int idx = 0;
	for (i = 0; i < 10; i++) {
		if (max == result[i]) {
			numbers[idx++] = i;
		}
	}
	
	printf("%d: ", max);
	for (i = 0; i < idx; i++) {
		printf("%d", numbers[i]);
		if (i < idx - 1) {
			printf(" ");
		}
	}
	return 0;
}

