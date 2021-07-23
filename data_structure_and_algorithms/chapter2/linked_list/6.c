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

void sort(Node head) {
	if (head == NULL || head->next == NULL)
		return;

	Node node = head->next;
	Node rear = NULL;

	for (;;) {
		while (node->next != rear) {
			Node next = node->next;
			if (node->data > next->data) {
				ElemType temp = node->data;
				node->data = next->data;
				next->data = temp;
			}
			node = next;
		}
		rear = node;
		node = head->next;
		if (rear == node)
			return;
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

	sort(head);

	print(head);

	return 0;
}









