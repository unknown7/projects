#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct point {
	int x;
	int y;
};

struct point* getStruct(struct point *p);
void output(struct point p);
void print(const struct point *p);

int main() {
	struct point p;
	printf("p=%p\n", &p);
	p = *getStruct(&p);
	output(*getStruct(&p));
	print(getStruct(&p));
	printf("p=%p\n", &p);
	
	struct point t = *getStruct(&p);
	printf("t=%p\n", &t);
	t = (struct point){10, 20};
	printf("t=%p\n", &t);
	
	return 0;
}

struct point* getStruct(struct point *p) {
	scanf("%d", &p->x);
	scanf("%d", &p->y);
	printf("Your input:x=%d,y=%d\n", p->x, p->y);
	return p;
}

void output(struct point p) {
	printf("output:x=%d,y=%d\n", p.x, p.y);
}

void print(const struct point *p) {
	printf("print:x=%d,y=%d\n", p->x, p->y);
}
