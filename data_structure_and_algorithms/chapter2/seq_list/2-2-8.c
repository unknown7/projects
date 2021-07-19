#include <stdio.h>
#include "seq_list.c"

int main(int argc, char const *argv[])
{
	list list = init();
	print_list(list);

	int a, b, c, boundary;

	boundary = 6;
	a = 1, b = list->len - boundary + 1, c = boundary + 1;

	printf("boundary=%d,a=%d,b=%d,c=%d", boundary, a, b ,c);
	printf("\n");

	int round = 1;
	while (c <= list->len) {
		int at = list->pn[a];
		int bt = list->pn[b];
		int ct = list->pn[c];

		list->pn[a] = ct;
		list->pn[b] = at;
		list->pn[c] = bt;

		a++;
		b++;
		c++;

		printf("round「%d」:", round++);
		print_list(list);
	}

	print_list(list);


	return 0;
}