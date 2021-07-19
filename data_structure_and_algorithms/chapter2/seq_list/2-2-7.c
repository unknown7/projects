#include <stdio.h>
#include "seq_list.c"

list merge(list, list);

int main(int argc, char const *argv[])
{
	list list1 = init();
	print_list(list1);

	list list2 = init();
	int i;
	for (i = 1; i <= list2->len; i++)
		list2->pn[i] *= 3;
	print_list(list2);

	sort(list1);
	sort(list2);

	list merge_result = merge(list1, list2);
	print_list(merge_result);

	return 0;
}

list merge(list list1, list list2) {
	int len, i, j, k;
	list result;
	
	len = list1->len + list2->len;
	i = j = k = 1;
	result = create(len);

	if (list1->pn[0] >= list2->pn[list2->len]) {

		for (; i <= list2->len; i++)
			result->pn[k++] = list2->pn[i];
		for (; i <= list1->len; i++)
			result->pn[k++] = list1->pn[i];

	} else if (list2->pn[0] >= list1->pn[list1->len]) {

		for (; i <= list1->len; i++)
			result->pn[k++] = list1->pn[i];
		for (; i <= list2->len; i++)
			result->pn[k++] = list2->pn[i];

	} else {
		
		while (i <= list1->len && j <= list2->len) {
			int a = list1->pn[i];
			int b = list2->pn[j];
			if (a < b) {
				result->pn[k++] = a;
				i++;
			} else {
				result->pn[k++] = b;
				j++;
			}
		}

		for (; i <= list1->len; i++)
			result->pn[k++] = list1->pn[i];
		for (; j <= list2->len; j++)
			result->pn[k++] = list2->pn[j];
	}

	result->len = k - 1;

	return result;
}
















