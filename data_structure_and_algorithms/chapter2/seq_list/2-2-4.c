#include <stdio.h>
#include "seq_list.c"

int main(int argc, char const *argv[])
{
	list list = init();
	print_list(list);

	int s = 3, t = 6;

	sort(list);

	int i = 1, j = list->len;

	while (list->pn[i] < s)
		i++;
	while (list->pn[j] > t)
		j--;

	while (j < list->len)
		list->pn[i++] = list->pn[++j];

	list->len -= j - i + 1;

	print_list(list);

	return 0;
}