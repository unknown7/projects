/*
习题9-4 查找书籍 （20 分）
给定n本书的名称和定价，本题要求编写程序，查找并输出其中定价最高和最低的书的名称和定价。

输入格式:
输入第一行给出正整数n（<10），随后给出n本书的信息。每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。题目保证没有同样价格的书。

输出格式:
在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。价格保留2位小数。

输入样例:
3
Programming in C
21.5
Programming in VB
18.5
Programming in Delphi
25.0
输出样例:
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

