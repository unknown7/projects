#include <stdio.h>
#include "seq_list.c"

int main(int argc, char const *argv[])
{
	int init_size = 10;
	list pnt = create(init_size);
	int i;
	for (i = 0; i < init_size; i++)
		insert(pnt, i, i);

	insert(pnt, 5, 11);
	print_list(pnt);
	printf("locate:%d, index:%d\n", 11, locate_element(pnt, 11));

	int min = delete_min_displace_last(pnt);

	printf("min:%d\n", min);
	print_list(pnt);

	return 0;
}
