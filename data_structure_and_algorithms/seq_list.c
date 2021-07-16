#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct seq_list {
	int* pn;
	int len;
} *list_pnt;

list_pnt create(int);
int insert(list_pnt, int, int);
void print_list(list_pnt);
int delete(list_pnt, int, int*);

int main(int argc, char const *argv[])
{
	int init_size = 10;
	list_pnt pnt = create(init_size);
	int i;
	for (i = 0; i < init_size; i++)
		insert(pnt, i, i);

	insert(pnt, 5, 11);

	print_list(pnt);

	int del = -1;
	delete(pnt, 5, &del);
	printf("delete:%d\n", del);

	print_list(pnt);

	return 0;
}

list_pnt create(int n) {
	if (n > SIZE)
		return NULL;
	list_pnt pnt = (list_pnt) malloc(sizeof(struct seq_list));
	pnt->pn = (int*) malloc(sizeof(int)*n);
	pnt->len = 0;
	return pnt;
}

int insert(list_pnt pnt, int index, int element) {
	if (index < 0 || index > SIZE)
		return 0;
	int i;
	for (i = pnt->len; i > index; i--)
		pnt->pn[i] = pnt->pn[i - 1];
	pnt->pn[i] = element;
	pnt->len++;
	return 1;
}

int delete(list_pnt pnt, int index, int *element) {
	if (index < 0 || index >= pnt->len)
		return 0;
	*element = pnt->pn[index];
	int i;
	for (i = index; i < pnt->len - 1; i++)
		pnt->pn[i] = pnt->pn[i + 1];
	pnt->len--;
	return 1;
}

void print_list(list_pnt pnt) {
	int i;
	for (i = 0; i < pnt->len; i++)
		printf(i + 1 < pnt->len ? "%d " : "%d", pnt->pn[i]);
	printf("\n");
}





