#include <stdio.h>
#include "seq_list.c"

int main(int argc, char const *argv[])
{
	int init_len, boundary, gap = 1;
	printf("init_len:");
	scanf("%d", &init_len);
	printf("boundary_index:");
	scanf("%d", &boundary);
	list list = init(init_len, gap);
	print_list(list);

	int left, right, offset;

	offset = list->len - boundary;
	left = 1, right = boundary + 1;

	printf("boundary=%d,left=%d,offset=%d,right=%d", boundary, left, offset, right);
	printf("\n");

	int round = 1;
	int* arr = list->pn;
	while (right <= list->len) {
		int o;
		int n = arr[right];
		int k = left;
		while (k <= right) {
			o = arr[k];
			arr[k] = n;
			n = o;
			k += offset;
		}
		left++;
		right++;
		printf("round「%d」:", round++);
		print_list(list);
	}

	print_list(list);


	return 0;
}