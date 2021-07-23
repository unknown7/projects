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

Node delete_by_recursion(Node head, ElemType data) {
	Node node = head;
	if (node == NULL)
		return node;

	if (node->data != data) {
		node->next = delete_by_recursion(node->next, data);
		return node;
	} else {
		Node next = node->next;
		free(node);
		return delete_by_recursion(next, data);
	}
}

void delete_by_loop(Node head, ElemType data) {
	Node node = head;
	while (node->next != NULL) {
		Node next = node->next;
		if (next->data != data) {
			node = next;
		} else {
			node->next = next->next;
			next->next = NULL;
			free(next);
		}
	}
}

int main() {
	Node head = init();
	int i;
	for (i = 0; i< 10; i++)
		insert(head, i);
	insert(head, 4);
	insert(head, 5);
	insert(head, 4);
	insert(head, 5);
	print(head);
	delete_by_recursion(head, 4);
	print(head);
	delete_by_loop(head, 5);
	print(head);
	return 0;
}

















