#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node *next;
} *Node;

void print(Node first) {
	Node node = first;
	while (node != NULL) {
		printf(node->next != NULL ? "%d " : "%d", node->data);
		node = node->next;
	}
	printf("\n");
}

Node insert(Node first, ElemType data) {
	Node node = (Node) malloc(sizeof(struct Node));
	node->data = data;
	node->next = first;
	return node;
}

Node delete(Node first, ElemType data) {
	Node node = first;
	if (node == NULL)
		return node;

	if (node->data != data) {
		node->next = delete(node->next, data);
		return node;
	} else {
		Node next = node->next;
		free(node);
		return delete(next, data);
	}
}

int main() {
	Node first, next = NULL;
	int i;
	for (i = 1; i <= 10; i++) {
		first = (Node) malloc(sizeof(struct Node));
		first->data = i;
		first->next = next;
		next = first;
	}
	print(first);
	first = insert(first, 7);
	first = insert(first, 4);
	first = insert(first, 2);
	first = insert(first, 7);
	print(first);
	first = delete(first, 4);
	print(first);
	return 0;
}





