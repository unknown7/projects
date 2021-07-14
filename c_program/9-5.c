/*
习题9-5 通讯录排序 （20 分）
输入n个朋友的信息，包括姓名、生日、电话号码，本题要求编写程序，按照年龄从大到小的顺序依次输出通讯录。题目保证所有人的生日均不相同。

输入格式:
输入第一行给出正整数n（<10）。随后n行，每行按照“姓名 生日 电话号码”的格式给出一位朋友的信息，其中“姓名”是长度不超过10的英文字母组成的字符串，“生日”是yyyymmdd格式的日期，“电话号码”是不超过17位的数字及+、-组成的字符串。

输出格式:
按照年龄从大到小输出朋友的信息，格式同输出。

输入样例:
3
zhang 19850403 13912345678
wang 19821020 +86-0571-88018448
qian 19840619 13609876543
输出样例:
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

