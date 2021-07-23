#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node *next;
} *Node;

static int MAX_INTEGER = 2147483647;

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

void delete_min(Node head) {
	if (head == NULL)
		return;

	Node prior = NULL, node = head;
	int min = MAX_INTEGER;
	while (node->next != NULL) {
		Node next = node->next;
		if (next->data < min) {
			min = next->data;
			prior = node;
		}
		node = next;
	}

	if (prior != NULL) {
		Node deleted = prior->next;
		prior->next = deleted->next;
		free(deleted);
	}
}

int main() {
	Node head = init();
	int i;
	for (i = 0; i< 10; i++)
		insert(head, i);

	insert(head, -4);
	insert(head, -66);
	insert(head, -999);
	insert(head, -3);
	insert(head, 8);

	print(head);

	delete_min(head);

	print(head);

	return 0;
}









