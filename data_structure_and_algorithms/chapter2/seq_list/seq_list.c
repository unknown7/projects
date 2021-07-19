#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct seq_list {
	int* pn;
	int len;
} *list;

list create(int);
list init();
int insert(list, int, int);
void print_list(list);
int delete(list, int, int*);
int locate_element(list, int);
void sort(list);
void q_sort(int*, int, int);
void swap(int*, int*);

// int main(int argc, char const *argv[])
// {
// 	int init_size = 10;
// 	list pnt = create(init_size);
// 	int i;
// 	for (i = 1; i <= init_size; i++)
// 		insert(pnt, i, i);

// 	insert(pnt, 5, 11);
// 	print_list(pnt);
// 	printf("locate:%d, index:%d\n", 11, locate_element(pnt, 11));

// 	int del = -1;
// 	delete(pnt, 2, &del);
// 	printf("delete:%d\n", del);
// 	print_list(pnt);

// 	sort(pnt);
// 	print_list(pnt);

// 	return 0;
// }

list create(int n) {
	if (n > SIZE)
		return NULL;
	list pnt = (list) malloc(sizeof(struct seq_list));
	pnt->pn = (int*) malloc(sizeof(int)*n);
	pnt->len = 0;
	return pnt;
}

list init() {
	list pnt = create(10);
	int i, j;
	for (i = 1; i <= 10; i++)
		insert(pnt, i, i);
	print_list(pnt);
	return pnt;
}

int insert(list pnt, int index, int element) {
	if (index < 1 || index > SIZE)
		return 0;
	int i;
	for (i = pnt->len + 1; i > index; i--)
		pnt->pn[i] = pnt->pn[i - 1];
	pnt->pn[i] = element;
	pnt->len++;
	return 1;
}

int delete(list pnt, int index, int *element) {
	if (index < 1 || index > pnt->len)
		return 0;
	*element = pnt->pn[index];
	int i;
	for (i = index; i < pnt->len; i++)
		pnt->pn[i] = pnt->pn[i + 1];
	pnt->len--;
	return 1;
}

int delete_min_displace_last(list pnt) {
	if (pnt == NULL || pnt->len == 0)
		return -1;
	int i, min_index = 1, min = pnt->pn[1];
	for (i = 1; i <= pnt->len; i++)
		if (pnt->pn[i] < min) {
			min_index = i;
			min = pnt->pn[i];
		}

	int result = pnt->pn[min_index];
	pnt->pn[min_index] = pnt->pn[pnt->len];
	pnt->len--;
	return result;
}

int locate_element(list pnt, int element) {
	if (pnt == NULL)
		return -1;
	int i;
	for (i = 1; i <= pnt->len; i++)
		if (pnt->pn[i] == element)
			return i;
	return -1;
}

void print_list(list pnt) {
	int i;
	for (i = 1; i <= pnt->len; i++)
		printf(i < pnt->len ? "%d " : "%d", pnt->pn[i]);
	printf("\n");
}

void sort(list pnt) {
	q_sort(pnt->pn, 1, pnt->len);
}

void q_sort(int* arr, int begin, int end) {
	if (begin >= end)
		return;

	int i = begin, j = end;
	int v = arr[i];

	while (i != j) {

		while (i < j && arr[j] >= v)
			j--;

		while (i < j && arr[i] <= v)
			i++;

		if (i < j)
			swap(&arr[i], &arr[j]);
	}

	if (begin < j)
		swap(&arr[begin], &arr[j]);

	q_sort(arr, begin, j - 1);
	q_sort(arr, j + 1, end);
}

void swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
























