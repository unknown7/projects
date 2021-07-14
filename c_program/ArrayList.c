#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayList.h"
const int BLOCK = 20;
ArrayList create(int size) {
	ArrayList list;
	list.size = size;
	list.array = (int*)malloc(list.size*sizeof(int));
	return list;
}
int size(const ArrayList *a) {
	return a->size;
}
int* at(ArrayList *a, int index) {
	if (index >= a->size) {
		inflate(a, (a->size/BLOCK+1)*BLOCK-a->size);
	}
	return &(a->array[index]);
}
void set(ArrayList *a, int index, int value) {
	if (index >= (a->size/BLOCK+1)*BLOCK-a->size) {
		inflate(a, 20);
	}
	*at(a, index) = value;
}
int get(ArrayList *a, int index) {
	return *at(a, index);
}
void inflate(ArrayList *a, int more_size) {
	int *p = (int*)malloc((a->size+more_size)*sizeof(int));
	int i;
	for (i = 0; i < a->size; i++) {
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size += more_size;
}
int main() {
	ArrayList list = create(3);
	int x = 0;
	int idx = 0;
	scanf("%d", &x);
	while (x != -1) {
		*at(&list, idx++) = x;
		scanf("%d", &x);
	}
	int i;
	for (i = 0; i < idx; i++) {
		printf("%d ", list.array[i]);
	}
	free(list.array);
	list.size=0;
	list.array=NULL;
}

