#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
int main() {
	LinkedList l = create();
	int x;
	scanf("%d", &x);
	while (x != -1) {
		add(&l, x);
		scanf("%d", &x);
	}
	printf("has:");
	scanf("%d", &x);
	printf("has(%d)=%d\n", x, has(&l, x));
	print(&l);
	printf("del:");
	scanf("%d", &x);
	printf("del(%d)=%d\n", x, del(&l, x));
	print(&l);
	return 0;
}

LinkedList create() {
	LinkedList l;
	l.head = l.tail = NULL;
	return l;
}
void add(LinkedList *pl, int value) {
	Node *pn = (Node*)malloc(sizeof(Node));
	pn->value = value;
	pn->next = NULL;
	if (pl->head && pl->tail) {
		pl->tail->next = pn;
		pl->tail = pn;
	} else {
		pl->head = pl->tail = pn;
	}
}
int has(LinkedList *pl, int value) {
	int h = 0;
	Node *c = pl->head;
	while (c) {
		if (c->value == value) {
			h = 1;
			break;
		}
		c = c->next;
	}
	return h;
}
int del(LinkedList *pl, int value) {
	int d = 0;
	if (pl->head && pl->tail) {
		if (pl->head == pl->tail && pl->head->value == value) {
			free(pl->head);
			free(pl->tail);
			d = 1;
		} else if (pl->head->value == value) {
			Node *h = pl->head;
			pl->head = pl->head->next;
			free(h);
			d = 1;
		} else if (pl->tail->value == value) {
			Node *c = pl->head;
			while (c) {
				if (c->next == pl->tail) {
					free(pl->tail);
					c->next = NULL;
					d = 1;
					break;
				}
				c = c->next;
			}
		} else {
			Node *c = pl->head;
			while (c) {
				if (c->next->value == value) {
					Node *n = c->next;
					c->next = c->next->next;
					free(n);
					d = 1;
					break;
				}
				c = c->next;
			}
		}
	}
	return d;
}
void print(LinkedList *pl) {
	Node *c = pl->head;
	while (c) {
		printf("%d ", c->value);
		c = c->next;
	}
	printf("\n");
}






