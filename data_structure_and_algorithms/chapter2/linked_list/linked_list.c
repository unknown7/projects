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
Linked_List locate_element(Linked_List, int);
void insert(Linked_List, int, int);
Linked_List delete(Linked_List, int);
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

Linked_List locate_element(Linked_List head, int element) {
	Linked_List node = head;
	while (node != NULL) {
		if (node->data == element)
			break;
		node = node->next;
	}
	return node;
}

void insert(Linked_List head, int index, int data) {
	Linked_List prev = locate_index(head, index - 1);
	if (prev != NULL) {
		Linked_List node = (Linked_List) malloc(sizeof(struct Node));
		node->data = data;
		node->next = prev->next;
		prev->next = node;
	}
}

Linked_List delete(Linked_List head, int index) {
	Linked_List node = NULL;
	Linked_List prev = locate_index(head, index - 1);
	if (prev != NULL) {
		node = prev->next;
		prev->next = node->next;
		free(node);
	}
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

	int index, element, insert_data_index, insert_data, delete_index;
	printf("locate index:");
	scanf("%d", &index);
	Linked_List node = locate_index(list, index);
	printf("locate index:%d=%d\n", index, node->data);
	printf("locate element:");
	scanf("%d", &element);
	node = locate_element(list, element);
	printf("locate element:%d=%d\n", element, node == NULL ? -999999 : node->data);
	printf("insert data index:");
	scanf("%d", &insert_data_index);
	printf("insert data:");
	scanf("%d", &insert_data);
	insert(list, insert_data_index, insert_data);

	print_list(list);

	printf("delete index:");
	scanf("%d", &delete_index);
	delete(list, delete_index);
	print_list(list);

	return 0;
}




















