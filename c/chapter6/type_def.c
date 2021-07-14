#include <stdio.h>

typedef struct {
	int size;
	char* arr;
} List;

int main(int argc, char const *argv[])
{
	List list;
	list.arr = "treat";

	unsigned char* p = (unsigned char *) &(list.arr);
	printf("%p\n", list.arr);

	int size = sizeof(void *);
	int i = size;
	while (--i >= 0)
		printf(i + 1 == size ? "%.2x" : " %.2x", *p++);
	printf("\n");

	printf("%d\n", list.size);
	printf("%c\n", *list.arr++);

	List* lp = &list;
	printf("%d\n", lp->size);
	printf("%c\n", *lp->arr++);
	printf("%c\n", *lp->arr);

	printf("%.2x\n", *list.arr);
	lp->arr++;
	printf("%p\n", lp->arr);
	p = (unsigned char *) &(lp->arr);
	i = size;
	while (--i >= 0)
		printf(i + 1 == size ? "%.2x" : " %.2x", *p++);
	printf("\n");

	int j = 17185;
	printf("%x\n", j);
	printf("%p\n", &j);
	int *jp = &j;
	p = (unsigned char *) &j;
	i = size;
	while (--i >= 0)
		printf(i + 1 == size ? "%.2x" : " %.2x", *p++);
	printf("\n");

	return 0;
}