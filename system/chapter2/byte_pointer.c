#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, int len) {
	int i;
	printf("%p\n", start);
	for (i = 0; i < len; i++)
		printf(" %.2x", *start++);
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_short(short x) {
	show_bytes((byte_pointer) &x, sizeof(short));
}

int main(int argc, char const *argv[]) {
	int value = 12345;
	show_int(value);
	show_float((float) value);
	show_pointer(&value);

	short x = 12345;
	short mx = -x;
	show_short(x);
	show_short(mx);
	return 0;
}