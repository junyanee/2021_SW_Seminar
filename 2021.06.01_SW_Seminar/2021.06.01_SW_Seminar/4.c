#include <stdio.h>

typedef struct point {
	int x;
	int y;
} Point;

void movePoint(Point origin, int xVal, int yVal);
int main(void) {

	Point p;
	int xVal = 0;
	int yVal = 0;

	printf("점의 x, y좌표, 이동할 x, y값을 순서대로 입력하시오: ");
	scanf("%d %d %d %d", p.x, p.y, &xVal, &yVal);
	movePoint(p, xVal, yVal);

	return 0;
}
void movePoint(Point origin, int xVal, int yVal) {
	origin.x = origin.x - xVal;
	origin.y = origin.y - yVal;
}