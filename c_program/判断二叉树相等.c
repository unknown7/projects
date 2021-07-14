/*
1�����������
2�����������һ���������нڵ� 
3����������ڶ����������нڵ�
4������������Ƿ���� 
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "BinTree.c"
int main() {
	int lcnt;
	scanf("%d", &lcnt);
	int x;
	scanf("%d", &x);
	BinTree tree = createTree(x);
	int i;
	for (i = 0; i < lcnt - 1; i++) {
		scanf("%d", &x);
		add(&tree, x);
	}
	Queue q = levelOrderResult(&tree);
	
	scanf("%d", &x);
	BinTree ct = createTree(x);
	int j;
	for (j = 0; j < lcnt - 1; j++) {
		scanf("%d", &x);
		add(&ct, x);
	}
	Queue cq = levelOrderResult(&ct);
	for (j = 0; j < lcnt; j++) {
		if ((deleteQ(&q))->data != (deleteQ(&cq))->data) {
			printf("not the same tree!");
			return 0;
		}
	}
	printf("same tree!");
	return 0;
}

