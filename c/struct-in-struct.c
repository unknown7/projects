#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define PRT(FMT, x) printf(FMT, x);
#define FMTDN "%d\n"
#define FMTPN "%p\n"

typedef struct {
	int x;
	int y;
} Point;
typedef struct {
	Point p1;
	Point p2;
} Rectangle;

Rectangle* changeR(Rectangle *r);
Point* changeP(Point *p, int x, int y);

int main() {
	Rectangle r = {
		{1, 2},
		{7, 8},
	};
	PRT(FMTDN, r.p1.x);
	changeP(&r.p1, 2, 3);
	PRT(FMTDN, r.p1.x);
	PRT(FMTDN, r.p1.x);
	changeR(&r);
	PRT(FMTDN, r.p1.x);
	PRT(FMTDN, r.p1.y);
	return 0;
}
Rectangle* changeR(Rectangle *r) {
	int v;
	scanf("%d", &v);
	changeP(&r->p1, v, v);
}
Point* changeP(Point *p, int x, int y) {
	p->x = x;
	p->y = y;
	return p;
}



