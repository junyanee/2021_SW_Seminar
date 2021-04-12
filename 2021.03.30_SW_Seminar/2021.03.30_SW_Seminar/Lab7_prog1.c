#include <stdio.h>

struct Point {
	int x;
	int y;
} point1, point2;
struct Rect {
	struct Point leftTop;
	struct Point rightBottom;
} rect;

int main(void) {

	int width, height;

	int rectInfo[5];

	printf("왼쪽 상단의 좌표 x,y, 오른쪽 하단의 좌표 x,y 를 입력하세요: \n");
	for (int i = 0; i < 4; i++) {
		scanf("%d", &rectInfo[i]);
	}
	rect.leftTop.x = rectInfo[0];
	rect.leftTop.y = rectInfo[1];	
	rect.rightBottom.x = rectInfo[2];
	rect.rightBottom.y = rectInfo[3];

	width = rect.rightBottom.x - rect.leftTop.x;
	height = rect.rightBottom.y - rect.leftTop.y;

	printf("왼쪽 상단 좌표: %d %d\n", rect.leftTop.x, rect.leftTop.y);
	printf("오른쪽 하단 좌표: %d %d\n", rect.rightBottom.x, rect.rightBottom.y);

	printf("폭은: %d\n", width);
	printf("높이는: %d\n", height);
	printf("넓이는: %d\n", width * height);


	return 0;
}

