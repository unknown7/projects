#include <stdio.h>
#include "seq_list.c"

int main(int argc, char const *argv[])
{
	list list = init();
	print_list(list);

	int s = 3, t = 6;

	sort(list);

	int i, k;
	for (i = 1, k = 1; i <= list->len; i++)
		if (list->pn[i] < s || list->pn[i] > t)
			list->pn[k++] = list->pn[i];

	list->len = k - 1;

	print_list(list);

	return 0;
}