#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} *Linked_List;

Linked_List init(void);
void head_insert(Linked_List);
void tail_insert(Linked_List);

Linked_List init() {
	Linked_List head = malloc(sizeof(struct Node));
	head->data = 0;
	head->next = NULL;
	head_insert(head);
	return head;
}

void head_insert(Linked_List head) {
	int data;
	scanf("%d", &data);
	while (data != -1) {
		Linked_List node = malloc(sizeof(struct Node));
		node->data = data;
		node->next = head->next;
		head->next = node;
		// length
		head->data++;
		scanf("%d", &data);
	}
}

void tail_insert(Linked_List head) {
	Linked_List prev = head;
	while (prev != NULL && prev->next != NULL)
		prev = prev->next;
	int data;
	scanf("%d", &data);
	while (data != -1) {
		Linked_List node = malloc(sizeof(struct Node));
		node->data = data;
		node->next = NULL;
		prev->next = node;
		prev = node;
		// length
		head->data++;
		scanf("%d", &data);
	}
}

void print_list(Linked_List head) {
	Linked_List node = head;
	while (node != NULL) {
		printf(node->next != NULL ? "%d " : "%d", node->data);
		node = node->next;
	}
	printf("\n");
}

int main() {
	Linked_List list = init();
	print_list(list);
	head_insert(list);
	print_list(list);
	tail_insert(list);
	print_list(list);
	return 0;
}




















