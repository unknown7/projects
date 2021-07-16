#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

Node* create(int);
Node* reverseLoop(Node*);
void print(Node*);
Node* reverseRecursion(Node*, Node*);

int main(int argc, char const *argv[])
{
	Node* first = create(0);
	print(first);
	first = reverseLoop(first);
	print(first);
	first = reverseRecursion(first, first->next);
	print(first);

	return 0;
}

Node* create(int value) {
	if (value == 10)
		return NULL;
	Node* node = (Node*) malloc(sizeof(Node));
	node->value = value;
	node->next = create(value + 1);
	return node;
}

Node* reverseLoop(Node* node) {
	if (node == NULL)
		return node;
	
	Node* pre = NULL;
	Node* current = node;

	while (current != NULL) {
		Node* next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}

	return pre;
}

Node* reverseRecursion(Node* node, Node* next) {
	Node* result = node;
	if (node == NULL)
		return node;
	if (next != NULL) {
		Node* nn = next->next;
		next->next = node;
		result = reverseRecursion(next, nn);
	}
	if (next != NULL && node->next == next && next->next == node)
		node->next = NULL;
	return result;
}

void print(Node* node) {
	while (node != NULL) {
		printf(node->next != NULL ? "%d " : "%d", node->value);
		node = node->next;
	}
	printf("\n");
}


