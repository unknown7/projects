#include <stdio.h>
#include "seq_list.c"

int locate(list, int);

int main(int argc, char const *argv[])
{
	list list = init(10, 3);
	print_list(list);
	sort(list);

	int i, x, left, right, middle, location;

	x = 9;
	location = locate(list, x);
	if (list->pn[location] == x) {
		if (location < list->len) {
			swap(&list->pn[location], &list->pn[location + 1]);
		}
	} else {
		for (i = list->len + 1; i > location + 1; i--)
			list->pn[i] = list->pn[i - 1];
		list->pn[location + 1] = x;
		list->len++;
	}

	print_list(list);

	return 0;
}

int locate(list list, int x) {

	int left, right, middle;

	left = 1, right = list->len;
	middle = (left + right) / 2;

	while (middle > left && middle < right) {

		int m = list->pn[middle];

		if (x > m) {
			left = middle;
			middle = (left + right) / 2;
		} else if (x < m) {
			right = middle;
			middle = (left + right) / 2;
		} else {
			break;
		}
	}

	return middle;
}







