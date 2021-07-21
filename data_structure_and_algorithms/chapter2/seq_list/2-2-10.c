#include <stdio.h>
#include "seq_list.c"

int locate(list, int);

int main(int argc, char const *argv[])
{

	int init_length, gaps, steps;
	printf("length of initialization:");
	scanf("%d", &init_length);
	printf("gaps:");
	scanf("%d", &gaps);
	printf("steps to moving right:");
	scanf("%d", &steps);

	list list = init(init_length, gaps);
	print_list(list);
	steps %= list->len;

	int left, right, offset;
	int old, new, k;
	int boundary, times, max_times, adjustment;
	int len = list->len;
	int* arr = list->pn;

	offset = steps, left = 1, right = len - offset + 1;
	adjustment = boundary = right;
	max_times = times = 0;
	int round = 1;
	while (right <= len) {
		new = arr[right];
		k = left;
		times = 0;
		while (k < boundary) {
			old = arr[k];
			arr[k] = new;
			new = old;
			k += offset;
			times++;
		}

		if (times >= max_times) {
			max_times = times;
			arr[right] = new;
		} else {
			int cursor = right;
			while (cursor > adjustment) {
				arr[cursor] = arr[cursor - 1];
				cursor--;
			}
			arr[cursor] = new;
			adjustment++;
		}

		left++;
		right++;
		printf("round「%d」:", round++);
		print_list(list);
	}

	print_list(list);

	return 0;
}