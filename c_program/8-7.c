/*
ϰ��8-7 �ַ������� ��20 �֣�
����Ҫ���д���򣬶���5���ַ���������С�����˳�������

�����ʽ��
����Ϊ�ɿո�ָ���5���ǿ��ַ�����ÿ���ַ����������ո��Ʊ�������з��ȿհ��ַ�������С��80��

�����ʽ��
�������¸�ʽ��������Ľ����

After sorted:
ÿ��һ���ַ���
����������
red yellow blue green white
���������
After sorted:
blue
green
red
white
yellow
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main() {
	const int SIZE = 5;
	char c[SIZE][80];
	char *p[SIZE];
	int i, j;
	for (i = 0; i < SIZE; i++) {
		scanf("%79s", c[i]);
		p[i] = c[i];
	}
	for (i = 0; i < SIZE; i++) {
		for (j = i; j < SIZE; j++) {
			if (strcmp(p[i], p[j]) > 0) {
				char *t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	printf("After sorted:\n");
	for (i = 0; i < SIZE; i++) {
		printf("%s\n", p[i]);
	}
	
	return 0;
}

