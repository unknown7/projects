#include <stdio.h>
#include "seq_list.c"

int main(int argc, char const *argv[])
{
	list list = init();
	insert(list, 3, 7);
	insert(list, 10, 7);
	print_list(list);

	int x = 7;
	int i, k = 1;
	for (i = 1; i <= list->len; i++) {
		if (list->pn[i] != x) {
			list->pn[k] = list->pn[i];
			k++;
		}
	}
	list->len = k - 1;

	print_list(list);

	return 0;
}