#ifndef _LinkedStack_H_
#define _LinkedStack_H_
typedef struct _node {
	int value;
	struct _node *prev;
	struct _node *next;
} Node;
typedef struct {
	int size;
	struct _node *cur;
} LinkedStack;
LinkedStack create();
void push(LinkedStack *s, int x);
int pop(LinkedStack *s);
int isEmpty(LinkedStack *s);
#endif
