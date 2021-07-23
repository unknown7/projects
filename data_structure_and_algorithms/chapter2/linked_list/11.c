#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node *next;
} *Node;

void print(Node head) {
	Node node = head->next;
	while (node != NULL) {
		printf(node->next != NULL ? "%d " : "%d", node->data);
		node = node->next;
	}
	printf("\n");
}

Node init() {
	Node head = (Node) malloc(sizeof(struct Node));
	head->data = 0; // length of list
	head->next = NULL;
	return head;
}

void insert(Node head, ElemType data) {
	Node node = (Node) malloc(sizeof(struct Node));
	node->data = data;
	node->next = head->next;
	head->next = node;
}

void separate(Node head, Node a, Node b) {
	if (head == NULL)
		return;

	Node node = head->next;
	if (node == NULL)
		return;

	Node next = node->next;
	if (next == NULL) {
		a->next = node;
		return;
	}

	a->next = node;
	b->next = next;
	while (next != NULL) {
		node->next = next->next;
		node = next;
		next = node->next;
	}
}

int main() {
	Node head = init();
	int i;
	for (i = 0; i< 10; i++)
		insert(head, i);

	insert(head, 9);
	insert(head, -4);
	insert(head, -66);
	insert(head, -999);
	insert(head, -3);
	insert(head, 8);

	print(head);

	Node a, b;

	a = (Node) malloc(sizeof(struct Node));
	b = (Node) malloc(sizeof(struct Node));

	separate(head, a, b);
	
	print(a);
	print(b);

	return 0;
}









