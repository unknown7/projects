/*
ϰ��9-4 �����鼮 ��20 �֣�
����n��������ƺͶ��ۣ�����Ҫ���д���򣬲��Ҳ�������ж�����ߺ���͵�������ƺͶ��ۡ�

�����ʽ:
�����һ�и���������n��<10����������n�������Ϣ��ÿ������һ���и��������������Ȳ�����30���ַ��������һ���и�����ʵ���۸���Ŀ��֤û��ͬ���۸���顣

�����ʽ:
��һ���а��ա��۸�, �������ĸ�ʽ�Ⱥ�����۸���ߺ���͵��顣�۸���2λС����

��������:
3
Programming in C
21.5
Programming in VB
18.5
Programming in Delphi
25.0
�������:
25.00, Programming in Delphi
18.50, Programming in VB
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char name[300];
	double price;
} Book;
int main() {
	int n;
	scanf("%d", &n);
	Book books[n];
	int i;
	for (i = 0; i < n; i++) {
		Book book;
		getchar();
		gets(book.name);
//		scanf("%2s", book.name);
		scanf("%lf", &book.price);
		books[i] = book;
	}
	
	int j, k;
	for (j = 0; j < n; j++) {
		for (k = j; k < n; k++) {
			if (books[j].price < books[k].price) {
				Book t = books[j];
				books[j] = books[k];
				books[k] = t;
			}
		}
	}
	
	printf("%.2f, %s", books[0].price, books[0].name);
	printf("\n");
	printf("%.2f, %s", books[n-1].price, books[n-1].name);
	return 0;
}

