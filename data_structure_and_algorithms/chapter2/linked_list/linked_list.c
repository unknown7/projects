#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} *Linked_List;

Linked_List init(void);
void head_insert(Linked_List);
void tail_insert(Linked_List);
Linked_List locate_index(Linked_List, int);
void print_list(Linked_List);

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

Linked_List locate_index(Linked_List head, int index) {
	if (head == NULL || index < 1 || index > head->data)
		return NULL;

	Linked_List node = head->next;
	int i = 1;
	while (i++ < index)
		node = node->next;

	return node;
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

	int locate_index;
	printf("locate:");
	scanf("%d", &locate_index);
	Linked_List node = locate_index(list, locate_index);
	printf("locate index:%d=%d\n", locate_index, node->data);
	return 0;
}




















