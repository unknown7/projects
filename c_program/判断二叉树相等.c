/*
1、输入结点个数
2、依次输入第一棵树的所有节点 
3、依次输入第二颗树的所有节点
4、输出两棵树是否相等 
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

