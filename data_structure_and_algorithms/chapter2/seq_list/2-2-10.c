#include <stdio.h>
#include "seq_list.c"

int locate(list, int);

int main(int argc, char const *argv[])
{

	int init_length, gaps, steps;
	printf("init length:");
	scanf("%d", &init_length);
	printf("gaps:");
	scanf("%d", &gaps);
	printf("steps of moving right:");
	scanf("%d", &steps);

	list list = init(init_length, gaps);
	print_list(list);
	steps %= list->len;

	int left, right, offset;
	int o, n, k, i;
	int point, times, max_times;
	int len = list->len;
	int* arr = list->pn;

	offset = steps, left = 1, right = len - offset + 1;
	point = right;
	int pp = point;
	max_times = times = 0;
	int round = 1;
	while (right <= len) {
		n = arr[right];
		k = left;
		times = 0;
		while (k < point) {
			o = arr[k];
			arr[k] = n;
			n = o;
			k += offset;
			times++;
		}

		if (times >= max_times) {
			max_times = times;
			arr[right] = n;
		} else {
			int cursor = right;
			while (cursor > pp) {
				arr[cursor] = arr[cursor - 1];
				cursor--;
			}
			arr[cursor] = n;
			pp++;
		}

		left++;
		right++;
		printf("round「%d」:", round++);
		print_list(list);
	}

	print_list(list);

	return 0;
}