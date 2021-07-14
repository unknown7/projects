#ifndef _LinkedList_H_
#define _LinkedList_H_
typedef struct _node {
	int value;
	struct _node *next;
} Node;
typedef struct {
	Node *head;
	Node *tail;
} LinkedList;
LinkedList create();
void add(LinkedList *pl, int value);
int has(LinkedList *pl, int value);
int del(LinkedList *pl, int value);
void print(LinkedList *pl);
#endif
