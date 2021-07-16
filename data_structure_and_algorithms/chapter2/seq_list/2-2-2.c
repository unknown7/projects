#include <stdio.h>
#include "seq_list.c"

void swap(int*, int*);

int main(int argc, char const *argv[])
{
	int init_size = 10;
	list pnt = create(init_size);
	int i, j;
	for (i = 0; i < init_size; i++)
		insert(pnt, i, i);

	print_list(pnt);

	while (j < i)
		swap(&pnt->pn[j++], &pnt->pn[--i]);

	print_list(pnt);

	return 0;
}

void swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
