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

void reverse(Node head) {
	if (head == NULL)
		return;

	Node node = head->next;
	Node prior, current;
	prior = NULL;
	current = node;

	while (current != NULL) {
		Node next = current->next;
		current->next = prior;
		prior = current;
		current = next;
	}

	head->next = prior;
}

int main() {
	Node head = init();
	int i;
	for (i = 0; i< 10; i++)
		insert(head, i);

	print(head);

	reverse(head);

	print(head);

	return 0;
}









