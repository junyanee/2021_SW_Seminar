#include <stdio.h>

struct point {
	double x;
	double y;
};
typedef struct point POINT;
POINT centerPoint, tempPoint;
POINT* p_center = &centerPoint;
struct rect {
	POINT leftTop;
	POINT rightBottom;
};
typedef struct rect RECT;
RECT Rect;
RECT* r = &Rect;
POINT CenterOfRect(POINT *, POINT *);
InputRect();
int main(void) {
	
	InputRect();
	CenterOfRect(&r->leftTop, &r->rightBottom);
	printf("중심은 %.2f %.2f입니다\n" , centerPoint);
	return 0;
}
POINT CenterOfRect(POINT * point1, POINT * point2) {
	double center1 = (r->rightBottom.x - r->leftTop.x) / 2.0;
	double center2 = (r->rightBottom.y - r->leftTop.y) / 2.0;
	p_center->x = center1;
	p_center->y = center2;
	return centerPoint;
}
InputRect() {
	printf("사각형의 좌상단 좌표를 입력하세요: \n");
	scanf("%lf %lf", &r->leftTop.x, &r->leftTop.y);
	printf("사각형의 우하단 좌표를 입력하세요: \n");
	scanf("%lf %lf", &r->rightBottom.x, &r->rightBottom.y);
	if (r->leftTop.x > r->rightBottom.x && r->leftTop.y > r->rightBottom.y) {
		tempPoint = r->leftTop;
		r->leftTop = r->rightBottom;
		r->rightBottom = tempPoint;
		printf("Normalized!\n");
	}
}