#include <stdio.h>

typedef struct point {
	int x;
	int y;
};
typedef struct point POINT;
POINT userPoint, tempPoint;
struct rect {
	POINT leftTop;
	POINT rightBottom;
}Rect;


int main(void) {

	printf("사각형의 좌상단 좌표를 입력하세요: \n");
	scanf("%d %d", &Rect.leftTop.x, &Rect.leftTop.y);

	printf("사각형의 우하단 좌표를 입력하세요: \n");
	scanf("%d %d", &Rect.rightBottom.x, &Rect.rightBottom.y);

	printf("확인하고 싶은 점의 좌표를 입력하세요: \n");
	scanf("%d %d", &userPoint.x, &userPoint.y);

	if (Rect.leftTop.x > Rect.rightBottom.x && Rect.leftTop.y > Rect.rightBottom.y) {
		tempPoint = Rect.leftTop;
		Rect.leftTop = Rect.rightBottom;
		Rect.rightBottom = tempPoint;
	}
	if (userPoint.x >= Rect.leftTop.x && userPoint.x <= Rect.rightBottom.x && 
		userPoint.y >= Rect.leftTop.y && userPoint.y <= Rect.rightBottom.y) {
		printf("점은 사각형 안에 있습니다");
	}
	else {
		printf("점은 사각형 밖에 있습니다");
	}
	return 0;
}