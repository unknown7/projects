#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "HashTable.h"
#define MAX_TABLE_SIZE 100000
int main() {
	HashTable t = create(8);
	printf("t.size=%d\n", t.size);
	
	put(&t, 1, "12223");
	HNode *n = get(&t, 1);
	printf("%s\n", n->value);
	
	put(&t, 1, "abc");
	n = get(&t, 1);
	printf("%s\n", n->value);
	return 0;
}
HashTable create(int size) {
	HashTable t;
	t.size = nextPrime(size);
	HNode *array = (HNode*)malloc(sizeof(HNode)*t.size);
	t.array = array;
	int i;
	for (i = 0; i < t.size; i++) {
		t.array[i].key = -1;
		t.array[i].value = '\0';
		t.array[i].next = NULL;
	}
	return t;
}
void put(HashTable *t, int key, char *value) {
	int pos = hash(t->size, key);
	HNode *head = &(t->array[pos]);
	HNode *n = head->next;
	while (n) {
		if (n->key != key) {
			n = n->next;
		} else {
			break;
		}
	}
	if (n) {
		strcpy(n->value, value);
	} else {
		HNode *node = (HNode*)malloc(sizeof(HNode));
		node->key = key;
		strcpy(node->value, value);
		node->next = head->next;
		head->next = node;
	}
}
HNode* get(HashTable *t, int key) {
	int pos = hash(t->size, key);
	HNode *head = &(t->array[pos]);
	HNode *n = head->next;
	while (n) {
		if (n->key != key) {
			n = n->next;
		} else {
			break;
		}
	}
	return n;
}
int hash(int size, int key) {
//	unsigned int h;
//	while (*key != '\0') {
//		h = (h << 5) + *key++;
//	}
//	return h % size;
	return key % size;
}
int nextPrime(int x) {
	int i, p = (x%2) ? x+2 : x+1;
	while (p < MAX_TABLE_SIZE) {
		for (i = (int)sqrt(p); i > 2; i--) {
			if (!(p%i)) {
				break;
			}
		}
		if (i == 2) {
			break;
		} else {
			p += 2;
		}
	}
	return p;
}
