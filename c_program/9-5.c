/*
ϰ��9-5 ͨѶ¼���� ��20 �֣�
����n�����ѵ���Ϣ���������������ա��绰���룬����Ҫ���д���򣬰�������Ӵ�С��˳���������ͨѶ¼����Ŀ��֤�����˵����վ�����ͬ��

�����ʽ:
�����һ�и���������n��<10�������n�У�ÿ�а��ա����� ���� �绰���롱�ĸ�ʽ����һλ���ѵ���Ϣ�����С��������ǳ��Ȳ�����10��Ӣ����ĸ��ɵ��ַ����������ա���yyyymmdd��ʽ�����ڣ����绰���롱�ǲ�����17λ�����ּ�+��-��ɵ��ַ�����

�����ʽ:
��������Ӵ�С������ѵ���Ϣ����ʽͬ�����

��������:
3
zhang 19850403 13912345678
wang 19821020 +86-0571-88018448
qian 19840619 13609876543
�������:
wang 19821020 +86-0571-88018448
qian 19840619 13609876543
zhang 19850403 13912345678
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char name[10];
	int birth;
	char mobile[17];
} Friend;
int main() {
	int n;
	scanf("%d", &n);
	Friend fs[n];
	int i;
	for (i = 0; i < n; i++) {
		Friend f;
		scanf("%s %d %s", f.name, &f.birth, f.mobile);
		fs[i] = f;
	}
	int j, k;
	for (j = 0; j < n; j++) {
		for (k = j + 1; k < n; k++) {
			Friend f1 = fs[j];
			Friend f2 = fs[k];
			if (f1.birth > f2.birth) {
				Friend t = f1;
				fs[j] = f2;
				fs[k] = t;
			}
		}
	}
	int l;
	for (l = 0; l < n; l++) {
		printf("%s %d %s\n", fs[l].name, fs[l].birth, fs[l].mobile);
	}
	return 0;
}

