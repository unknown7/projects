#ifndef _LinkedQueue_H_
#define _LinkedQueue_H_
typedef struct _node {
	int value;
	struct _node *next;
} Node;
typedef struct {
	struct _node *front;
	struct _node *rear;
	int size;
} LinkedQueue;
LinkedQueue create();
int isEmpty(LinkedQueue *q);
int addQ(LinkedQueue *q, int x);
int deleteQ(LinkedQueue *q);
#endif
