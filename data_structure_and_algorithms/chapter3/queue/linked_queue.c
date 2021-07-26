#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node *next;
} *Node;

typedef struct Queue {
	Node front, rear;
} *Queue;

Queue init() {
	Queue q = (Queue) malloc(sizeof(struct Queue));
	Node n = (Node) malloc(sizeof(struct Node));
	q->front = q->rear = n;
	return q;
}

int is_empty(Queue q) {
	return q->front == q->rear;
}

void enqueue(Queue q, ElemType data) {
	Node n = (Node) malloc(sizeof(struct Node));
	n->data = data;
	q->rear->next = n;
	q->rear = n;
}

ElemType dequeue(Queue q) {
	ElemType result = -1;
	if (!is_empty(q)) {
		Node n = q->front->next;
		result = n->data;
		q->front->next = n->next;
		if (q->rear == n)
			q->rear = q->front;
		free(n);
	} else {
		printf("queue is empty!\n");
	}
	return result;
}

int main() {
	Queue q = init();

	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);

	printf("%d\n", dequeue(q));
	printf("%d\n", dequeue(q));
	printf("%d\n", dequeue(q));

	return 0;
}















