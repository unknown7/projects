#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "BinTree.h"
#define PRINTLN printf("\n");
#define SIZE 10
#define MAX_DATA 50
int main() {
	BinTree tree = createTree(rand() % MAX_DATA);
	int i;
	for (i = 0; i < SIZE; i++) {
		add(&tree, rand() % MAX_DATA);
	}
	printf("pre recursion:\t");
	preOrderRecursion(&tree);
	PRINTLN;
	printf("pre loop:\t");
	preOrderLoop(&tree);
	PRINTLN;
	printf("in recursion:\t");
	inOrderRecursion(&tree);
	PRINTLN;
	printf("in loop:\t");
	inOrderLoop(&tree);
	PRINTLN;
	printf("post recursion:\t");
	postOrderRecursion(&tree);
	PRINTLN;
	printf("post loop:\t");
	postOrderLoop(&tree);
	PRINTLN;
	printf("level order:\t");
	levelOrder(&tree);
	PRINTLN;
	printf("find x:\t");
	int x;
	scanf("%d", &x);
	BinTree *f = find(&tree, x);
	if (f) {
		printf("%d", f->data);
	} else {
		printf("<find> There is no node in the BinTree with a data of:%d", x);
	}
	PRINTLN;
	printf("min:\t");
	BinTree *min = findMin(&tree);
	printf("%d", min->data);
	PRINTLN;
	printf("max:\t");
	BinTree *max = findMax(&tree);
	printf("%d", max->data);
	PRINTLN;
	printf("delete x: ");
	scanf("%d", &x);
	BinTree *d = deleteTreeNode(&tree, x);
	if (d != &tree) {
		printf("delete:%d success! in loop: ", d->data);
		inOrderLoop(&tree);
	}
	return 0;
}
BinTree createTree(int x) {
	BinTree *tree = (BinTree*)malloc(sizeof(BinTree));
	tree->data = x;
	tree->left = NULL;
	tree->right = NULL;
	return *tree;
}
void add(BinTree *tree, int x) {
	BinTree *cur;
	int direct; 
	while (tree) {
		cur = tree;
		if (x <= tree->data) {
			direct = 0;
			tree = tree->left;
		} else {
			direct = 1;
			tree = tree->right;
		}
	}
	BinTree *t = (BinTree*)malloc(sizeof(BinTree));
	t->data = x;
	t->left = NULL;
	t->right = NULL;
	switch(direct) {
		case 0:
			cur->left = t;
			break;
		case 1:
			cur->right = t;
			break;
	}
}
void preOrderRecursion(BinTree *tree) {
	if (tree) {
		printf("%d ", tree->data);
		preOrderRecursion(tree->left);
		preOrderRecursion(tree->right);
	}
}
void preOrderLoop(BinTree *tree) {
	Stack s = createStack();
	while (tree || !isEmptyStack(&s)) {
		while (tree) {
			printf("%d ", tree->data);
			push(&s, tree);
			tree = tree->left;
		}
		if (!isEmptyStack(&s)) {
			tree = pop(&s);
			tree = tree->right;
		}
	}
}
void inOrderRecursion(BinTree *tree) {
	if (tree) {
		inOrderRecursion(tree->left);
		printf("%d ", tree->data);
		inOrderRecursion(tree->right);
	}
}
void inOrderLoop(BinTree *tree) {
	Stack s = createStack();
	while (tree || !isEmptyStack(&s)) {
		while (tree) {
			push(&s, tree);
			tree = tree->left;
		}
		if (!isEmptyStack(&s)) {
			tree = pop(&s);
			printf("%d ", tree->data);
			tree = tree->right;
		}
	}
}
void postOrderRecursion(BinTree *tree) {
	if (tree) {
		postOrderRecursion(tree->left);
		postOrderRecursion(tree->right);
		printf("%d ", tree->data);
	}
}
void postOrderLoop(BinTree *tree) {
	Stack s1 = createStack();
	Stack s2 = createStack();
	while (tree || !isEmptyStack(&s1)) {
		while (tree) {
			push(&s1, tree);
			push(&s2, tree);
			tree = tree->right;
		}
		if (!isEmptyStack(&s1)) {
			tree = pop(&s1);
			tree = tree->left;
		}
	}
	while (!isEmptyStack(&s2)) {
		tree = pop(&s2);
		printf("%d ", tree->data);
	}
}
void levelOrder(BinTree *tree) {
	Queue q = createQueue();
	addQ(&q, tree);
	while (!isEmptyQueue(&q)) {
		tree = deleteQ(&q);
		printf("%d ", tree->data);
		if (tree->left) {
			addQ(&q, tree->left);
		}
		if (tree->right) {
			addQ(&q, tree->right);
		}
	}
}
Queue levelOrderResult(BinTree *tree) {
	Queue q = createQueue();
	Queue result = createQueue();
	addQ(&q, tree);
	while (!isEmptyQueue(&q)) {
		tree = deleteQ(&q);
		addQ(&result, tree);
		if (tree->left) {
			addQ(&q, tree->left);
		}
		if (tree->right) {
			addQ(&q, tree->right);
		}
	}
	return result;
}
BinTree* find(BinTree *tree, int x) {
	while (tree) {
		if (x < tree->data) {
			tree = tree->left;
		} else if (x > tree->data) {
			tree = tree->right;
		} else {
			return tree;
		}
	}
	return NULL;
}
BinTree* findMin(BinTree *tree) {
	if (tree) {
		while (tree->left) {
			tree = tree->left;
		}
	}
	return tree;
}
BinTree* findMax(BinTree *tree) {
	if (tree) {
		while (tree->right) {
			tree = tree->right;
		}
	}
	return tree;
}
BinTree* deleteTreeNode(BinTree *tree, int x) {
	BinTree *temp;
	if (!tree) {
		printf("<deleteTreeNode> There is no node in the BinTree with a data of:%d", x);
	} else {
		if (x < tree->data) {
			tree->left = deleteTreeNode(tree->left, x);
		} else if (x > tree->data) {
			tree->right = deleteTreeNode(tree->right, x);
		} else {
			if (tree->left && tree->right) {
				temp = findMax(tree->left);
				tree->data = temp->data;
				tree->left = deleteTreeNode(tree->left, tree->data);
			} else {
				temp = tree;
				if (!tree->left) {
					tree = tree->right;
				} else if (!tree->right) {
					tree = tree->left;
				}
				free(temp);
			}
		}
	}
	return tree;
}

Stack createStack() {
	Stack s;
	s.size = 0;
	s.cur = NULL;
	return s;
}
void push(Stack *s, BinTree *data) {
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	s->size++;
	if (s->cur) {
		s->cur->next = n;
		n->prev= s->cur;
		s->cur = n;
	} else {
		s->cur = n;
		n->prev = NULL;
	}
}
BinTree* pop(Stack *s) {
	BinTree *tree = NULL;
	if (s->cur != NULL) {
		Node *p = s->cur;
		tree = p->data;
		s->cur = p->prev;
		free(p);
		s->size--;
	}
	return tree;
}
int isEmptyStack(Stack *s) {
	return s->size <= 0;
}
Queue createQueue() {
	Queue q;
	q.size = 0;
	q.front = q.rear = NULL;
	return q;
}
void addQ(Queue *q, BinTree *data) {
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	if (isEmptyQueue(q)) {
		q->front = q->rear = n;
	} else {
		n->prev = q->rear;
		q->rear->next = n;
		q->rear = n;
	}
	q->size++;
}
BinTree* deleteQ(Queue *q) {
	BinTree *t;
	if (isEmptyQueue(q)) {
		t = NULL;
	} else {
		Node *n = q->front;
		q->front = n->next;
		t = n->data;
		free(n);
		q->size--;
	}
	return t;
}
int isEmptyQueue(Queue *q) {
	return q->size <= 0;
}



































































