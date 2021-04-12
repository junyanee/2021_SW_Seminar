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

	printf("���� ����� ��ǥ x,y, ������ �ϴ��� ��ǥ x,y �� �Է��ϼ���: \n");
	for (int i = 0; i < 4; i++) {
		scanf("%d", &rectInfo[i]);
	}
	rect.leftTop.x = rectInfo[0];
	rect.leftTop.y = rectInfo[1];	
	rect.rightBottom.x = rectInfo[2];
	rect.rightBottom.y = rectInfo[3];

	width = rect.rightBottom.x - rect.leftTop.x;
	height = rect.rightBottom.y - rect.leftTop.y;

	printf("���� ��� ��ǥ: %d %d\n", rect.leftTop.x, rect.leftTop.y);
	printf("������ �ϴ� ��ǥ: %d %d\n", rect.rightBottom.x, rect.rightBottom.y);

	printf("����: %d\n", width);
	printf("���̴�: %d\n", height);
	printf("���̴�: %d\n", width * height);


	return 0;
}

