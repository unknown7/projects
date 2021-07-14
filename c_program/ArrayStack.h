#ifndef _ArrayStack_H_
#define _ArrayStack_H_

typedef struct {
	int *array;
	int size;
	int cur;
} ArrayStack;

int push(ArrayStack *s, int x);
int pop(ArrayStack *s);
ArrayStack create();
int inflate(ArrayStack *s, int more_size);
void doPush(ArrayStack *s, int x);
#endif
