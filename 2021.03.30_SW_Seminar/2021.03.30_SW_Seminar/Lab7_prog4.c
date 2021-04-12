#include <stdio.h>

struct point {
	int x;
	int y;
};
typedef struct point POINT;
POINT userPoint, tempPoint;
struct rect {
	POINT leftTop;
	POINT rightBottom;
};
typedef struct rect RECT;
RECT Rect;

int PrintRect();
int isPointInRect(POINT, RECT);
int NormalizeRect(POINT, POINT);

int width, height;

int main(void) {

	printf("사각형의 좌상단 좌표를 입력하세요: \n");
	scanf("%d %d", &Rect.leftTop.x, &Rect.leftTop.y);

	printf("사각형의 우하단 좌표를 입력하세요: \n");
	scanf("%d %d", &Rect.rightBottom.x, &Rect.rightBottom.y);

	if (Rect.leftTop.x > Rect.rightBottom.x && Rect.leftTop.y > Rect.rightBottom.y) {
		NormalizeRect(Rect.leftTop, Rect.rightBottom);
	}
	PrintRect();

	printf("확인하고 싶은 점의 좌표를 입력하세요: \n");
	scanf("%d %d", &userPoint.x, &userPoint.y);

	isPointInRect(userPoint, Rect);
	return 0;
}
int PrintRect() {
	width = Rect.rightBottom.x - Rect.leftTop.x;
	height = Rect.rightBottom.y - Rect.leftTop.y;

	printf("왼쪽 상단 좌표: %d %d\n", Rect.leftTop.x, Rect.leftTop.y);
	printf("오른쪽 하단 좌표: %d %d\n", Rect.rightBottom.x, Rect.rightBottom.y);
	printf("폭은: %d\n", width);
	printf("높이는: %d\n", height);
	printf("넓이는: %d\n", width * height);
}
int isPointInRect(POINT point, RECT rect) {
	if (userPoint.x >= Rect.leftTop.x && userPoint.x <= Rect.rightBottom.x &&
		userPoint.y >= Rect.leftTop.y && userPoint.y <= Rect.rightBottom.y) {
		printf("점은 사각형 안에 있습니다");
	}
	else {
		printf("점은 사각형 밖에 있습니다");
	}
	return 0;
}
int NormalizeRect(POINT leftTop, POINT rightBottom) {
	tempPoint = Rect.leftTop;
	Rect.leftTop = Rect.rightBottom;
	Rect.rightBottom = tempPoint;
	printf("Normalize Completed...\n");
}