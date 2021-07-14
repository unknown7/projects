#include <stdio.h>

struct point
{
	int x;
	int y;
} pt;

struct rect
{
	struct point pt1;
	struct point pt2;
};

struct ps {
	int len;
	char* str;
} psp;

int main(int argc, char const *argv[])
{
	pt.x = 30, pt.y = 2;
	struct point p = {50, 4};
	struct rect r = {pt, p};

	printf("%d,%d\n", pt.x, pt.y);
	printf("%d,%d\n", p.x, p.y);

	printf("%d,%d\n", r.pt1.x, r.pt1.y);

	char* pointer = "abc";
	printf("%c\n", *(pointer++));
	printf("%c\n", *pointer);

	struct ps* pp = &psp;
	pp->str = "treat";
	printf("%d\n", pp->len);

	printf("%p\n", pp);
	// pp++;
	printf("%s\n", pp->str);
	printf("%p\n", pp);
	printf("%d\n", pp->len++);
	printf("%d\n", ++pp->len);
	int* in = &(pp->len);
	printf("%d\n", *in);

	printf("%s\n", pp->str);
	printf("%s\n", pp->str++);
	printf("%s\n", pp->str);
	printf("%s\n", ++pp->str);
	printf("%s\n", pp++->str);
	printf("%s\n", pp->str);

	pp--;
	char c = *pp->str++;
	printf("%c\n", c);
	c = *pp->str;
	printf("%c\n", c);

	c = *++pp->str;
	printf("%c\n", c);
	c = *pp->str;
	printf("%c\n", c);

	return 0;
}













