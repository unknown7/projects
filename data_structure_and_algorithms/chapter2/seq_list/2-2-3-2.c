#include <stdio.h>
#include "seq_list.c"

int main(int argc, char const *argv[])
{
	list list = init();
	insert(list, 3, 7);
	insert(list, 10, 7);
	print_list(list);

	int x = 7;
	int i = 0, k = 0;
	while (i <= list->len) {
		if (list->pn[i] == x)
			k++;
		else
			list->pn[i - k] = list->pn[i];
		i++;
	}

	list->len -= k;

	print_list(list);

	return 0;
}