/**
	����������ȷ����[0,9]��Χ�ڵ�������ͳ��ÿһ�����ֳ��ֵĴ��� 
*/
#include <stdio.h>
#include <math.h>
int main() {
	const int SIZE = 10;
	int arr[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		arr[i] = 0;
	}
	int x;
	printf("������:");
	scanf("%d", &x);
	while (x != -1) {
		arr[x]++;
		printf("������:");
		scanf("%d", &x);
	}
	for (i = 0; i < SIZE; i++) {
		printf("%d������%d��\n", i, arr[i]);
	}
	return 0;
}

