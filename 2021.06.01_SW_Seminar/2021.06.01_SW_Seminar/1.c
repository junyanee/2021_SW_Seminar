#include <stdio.h>
#include <math.h>

typedef struct point{
	int x;
	int y;
} Point2D;

Point2D points[4];
double length = 0.0;

int main(void) {

	for (int i = 0; i < sizeof(points) / sizeof(Point2D); i++) {
		points[i].x = (i+1) * 10;
		points[i].y = (i+1) * 10;
	}

	for (int i = 0; i < sizeof(points) / sizeof(Point2D) - 1; i++) {
		int xLength = points[i + 1].x - points[i].x;
		int yLength = points[i + 1].y - points[i].y;

		length += sqrt((xLength * xLength) + (yLength * yLength));
	}
	printf("%f", length);

	return 0;
}
