#ifndef _HashTable_H_
#define _HashTable_H_
typedef struct _hnode {
	int key;
	char *value;
	struct _hnode *next;
} HNode;
typedef struct {
	int size;
	struct _hnode *array;
} HashTable;
HashTable create(int size);
void put(HashTable *t, int key, char *value);
HNode* get(HashTable *t, int key);
int hash(int size, int key);
int nextPrime(int x);
#endif
