#include <stdio.h>
#include "seq_list.c"

int main(int argc, char const *argv[])
{
	list list = init();
	print_list(list);

	insert(list, 2, 8);
	insert(list, 2, 9);
	insert(list, 1, 3);
	insert(list, 7, 3);
	insert(list, 5, 9);

	print_list(list);

	sort(list);

	print_list(list);

	int i, k;
	for (i = 1, k = 1; i <= list->len; i++)
		if (list->pn[i] < list->pn[i + 1] || i == list->len)
			list->pn[k++] = list->pn[i];

	list->len = k - 1;

	print_list(list);

	return 0;
}