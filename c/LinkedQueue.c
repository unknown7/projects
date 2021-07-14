#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedQueue.h"
int main() {
	LinkedQueue q = create();
	int i;
	for (i = 0; i < 3; i++) {
		int j;
		for (j = 0; j < 7; j++) {
			addQ(&q, rand() % 100);
		}
	}
	
	int x;
	while ((x = deleteQ(&q)) != EOF) {
		printf("%d\t", x);
	}
	return 0;
}
LinkedQueue create() {
	LinkedQueue q;
	q.front = q.rear = NULL;
	q.size = 0;
	return q;
}
int isEmpty(LinkedQueue *q) {
	return q->rear == NULL;
}
int addQ(LinkedQueue *q, int x) {
	int ret = 1;
	Node *n = (Node*)malloc(sizeof(Node));
	n->value = x;
	n->next = NULL;
	if (q->front != NULL) {
		q->front->next = n;
	}
	q->front = n;
	q->size++;
	if (q->rear == NULL) {
		q->rear = q->front;
	}
	return ret;
}
int deleteQ(LinkedQueue *q) {
	int x;
	if (!isEmpty(q)) {
		Node *n = q->rear;
		x = n->value;
		q->rear = n->next;
		free(n);
	} else {
		x = EOF;
	}
	return x;
}





