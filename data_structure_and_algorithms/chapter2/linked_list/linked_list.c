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
void insert_index(Linked_List, int, int);
Linked_List insert_before(Linked_List, Linked_List, int);
Linked_List remove_index(Linked_List, int);
void remove_node(Linked_List, Linked_List);
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
	if (head == NULL || index < 0 || index > head->data)
		return NULL;

	Linked_List node = head;
	int i = 0;
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

void insert_index(Linked_List head, int index, int data) {
	Linked_List prev = locate_index(head, index - 1);
	if (prev != NULL) {
		Linked_List node = (Linked_List) malloc(sizeof(struct Node));
		node->data = data;
		node->next = prev->next;
		prev->next = node;
	}
}

Linked_List insert_before(Linked_List head, Linked_List element, int data) {
	Linked_List node = NULL, prev = head;
	// 1、traditional
	// while (prev != NULL && prev->next != element)
	// 	prev = prev->next;
	// if (prev != NULL) {
	// 	node = (Linked_List) malloc(sizeof(struct Node));
	// 	node->data = data;
	// 	node->next = element;
	// 	prev->next = node;
	// }
	// return node;
	// 2、exchange
	node = (Linked_List) malloc(sizeof(struct Node));
	node->data = data;
	node->next = element->next;
	element->next = node;
	int temp = element->data;
	element->data = node->data;
	node->data = temp;
	return node;
}

Linked_List remove_index(Linked_List head, int index) {
	Linked_List node = NULL;
	Linked_List prev = locate_index(head, index - 1);
	if (prev != NULL) {
		node = prev->next;
		prev->next = node->next;
		head->data--;
		free(node);
	}
	return node;
}

void remove_node(Linked_List head, Linked_List node) {
	// 1、tradational
	Linked_List n = head;
	while (n != NULL && n->next != node)
		n = n->next;
	if (n != NULL) {
		n->next = node->next;
		head->data--;
		free(node);
	}
	// 2、exchange
	// Linked_List next = node->next;
	// node->data = next->data;
	// node->next = next->next;
	// free(next);
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
	insert_index(list, insert_data_index, insert_data);

	print_list(list);

	printf("delete index:");
	scanf("%d", &delete_index);
	remove_index(list, delete_index);
	print_list(list);

	printf("locate index:");
	scanf("%d", &index);
	node = locate_index(list, index);
	insert_before(list, node, 98);
	printf("%d\n", node->data);
	print_list(list);
	remove_node(list, node);
	print_list(list);

	return 0;
}




















