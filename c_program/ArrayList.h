#ifndef _ArrayList_H_
#define _ArrayList_H_
typedef struct {
	int size;
	int *array;
} ArrayList;
ArrayList create(int size);
int size(const ArrayList *a);
int* at(ArrayList *a, int index);
void inflate(ArrayList *a, int more_size);
#endif
