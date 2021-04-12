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

	printf("�簢���� �»�� ��ǥ�� �Է��ϼ���: \n");
	scanf("%d %d", &Rect.leftTop.x, &Rect.leftTop.y);

	printf("�簢���� ���ϴ� ��ǥ�� �Է��ϼ���: \n");
	scanf("%d %d", &Rect.rightBottom.x, &Rect.rightBottom.y);

	if (Rect.leftTop.x > Rect.rightBottom.x && Rect.leftTop.y > Rect.rightBottom.y) {
		NormalizeRect(Rect.leftTop, Rect.rightBottom);
	}
	PrintRect();

	printf("Ȯ���ϰ� ���� ���� ��ǥ�� �Է��ϼ���: \n");
	scanf("%d %d", &userPoint.x, &userPoint.y);

	isPointInRect(userPoint, Rect);
	return 0;
}
int PrintRect() {
	width = Rect.rightBottom.x - Rect.leftTop.x;
	height = Rect.rightBottom.y - Rect.leftTop.y;

	printf("���� ��� ��ǥ: %d %d\n", Rect.leftTop.x, Rect.leftTop.y);
	printf("������ �ϴ� ��ǥ: %d %d\n", Rect.rightBottom.x, Rect.rightBottom.y);
	printf("����: %d\n", width);
	printf("���̴�: %d\n", height);
	printf("���̴�: %d\n", width * height);
}
int isPointInRect(POINT point, RECT rect) {
	if (userPoint.x >= Rect.leftTop.x && userPoint.x <= Rect.rightBottom.x &&
		userPoint.y >= Rect.leftTop.y && userPoint.y <= Rect.rightBottom.y) {
		printf("���� �簢�� �ȿ� �ֽ��ϴ�");
	}
	else {
		printf("���� �簢�� �ۿ� �ֽ��ϴ�");
	}
	return 0;
}
int NormalizeRect(POINT leftTop, POINT rightBottom) {
	tempPoint = Rect.leftTop;
	Rect.leftTop = Rect.rightBottom;
	Rect.rightBottom = tempPoint;
	printf("Normalize Completed...\n");
}