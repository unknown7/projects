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

void delte_min(Node head) {
	if (head == NULL || head->next == NULL)
		return;

	Node prior = head->next;
	Node current = prior->next;
	Node p = head;
	if (current == NULL) {
		printf("%d", prior->data);
		free(prior);
		head->next = NULL;
		return;
	}

	for (;;) {
		while (current != NULL) {
			if (prior->data < current->data) {
				int temp = prior->data;
				prior->data = current->data;
				current->data = temp;
			}
			p = prior;
			prior = current;
			current = current->next;
		}
		printf("%d ", prior->data);
		p->next = NULL;
		p = head;
		free(prior);
		prior = head->next;
		if (prior == NULL)
			return;
		current = prior->next;
	}
	printf("\n");
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

	delte_min(head);

	return 0;
}









