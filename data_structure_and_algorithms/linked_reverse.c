#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

Node* create(int);
Node* reverse(Node*);
void print(Node*);

int main(int argc, char const *argv[])
{
	Node* first = create(0);
	print(first);
	first = reverse(first);
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

Node* reverse(Node* node) {
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

Node* reverse(Node* node) {
	if (node == NULL)
		return node;

}

void print(Node* node) {
	while (node != NULL) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}


