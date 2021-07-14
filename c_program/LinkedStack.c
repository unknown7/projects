#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedStack.h"
int main() {
	LinkedStack s = create();
	int i;
	for (i = 0; i < 30; i++) {
		push(&s, i);
	}
	while (s.cur) {
		printf("%d ", pop(&s));
	}
	return 0;
}
LinkedStack create() {
	LinkedStack s;
	s.size = 0;
	s.cur = NULL;
	return s;
}
void push(LinkedStack *s, int x) {
	Node *n = (Node*)malloc(sizeof(Node));
	n->value = x;
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
int pop(LinkedStack *s) {
	int x = EOF;
	if (s->cur != NULL) {
		Node *p = s->cur;
		x = p->value;
		s->cur = p->prev;
		free(p);
		s->size--;
	}
	return x;
}
int isEmpty(LinkedStack *s) {
	return s->size > 0;
}








