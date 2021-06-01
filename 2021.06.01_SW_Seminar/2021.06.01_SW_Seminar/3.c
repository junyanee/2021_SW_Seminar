#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x;
	int y;
} Point2D;

Point2D* allocPoint();

int main(void) {

	Point2D* p;
	p = allocPoint();

	printf("°á°ú: %d %d\n", p->x, p->y);

	return 0;
}

Point2D* allocPoint() {
	Point2D* p = malloc(sizeof(Point2D));
	p->x = 10;
	p->y = 20;
}