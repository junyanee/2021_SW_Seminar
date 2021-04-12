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

	printf("�簢���� �»�� ��ǥ�� �Է��ϼ���: \n");
	scanf("%d %d", &Rect.leftTop.x, &Rect.leftTop.y);

	printf("�簢���� ���ϴ� ��ǥ�� �Է��ϼ���: \n");
	scanf("%d %d", &Rect.rightBottom.x, &Rect.rightBottom.y);

	printf("Ȯ���ϰ� ���� ���� ��ǥ�� �Է��ϼ���: \n");
	scanf("%d %d", &userPoint.x, &userPoint.y);

	if (Rect.leftTop.x > Rect.rightBottom.x && Rect.leftTop.y > Rect.rightBottom.y) {
		tempPoint = Rect.leftTop;
		Rect.leftTop = Rect.rightBottom;
		Rect.rightBottom = tempPoint;
	}
	if (userPoint.x >= Rect.leftTop.x && userPoint.x <= Rect.rightBottom.x && 
		userPoint.y >= Rect.leftTop.y && userPoint.y <= Rect.rightBottom.y) {
		printf("���� �簢�� �ȿ� �ֽ��ϴ�");
	}
	else {
		printf("���� �簢�� �ۿ� �ֽ��ϴ�");
	}
	return 0;
}