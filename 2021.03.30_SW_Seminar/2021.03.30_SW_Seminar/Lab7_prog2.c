#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
}start, end;
typedef struct point POINT;
struct line {
	POINT start;
	POINT end;
};
POINT *p_start = &start;
POINT *p_end = &end;

int main(void) {

	printf("�������� ��ǥ�� �Է��ϼ���: \n");
	scanf("%d %d", &p_start->x, &p_start->y);

	printf("������ ��ǥ�� �Է��ϼ���: \n");
	scanf("%d %d", &p_end->x, &p_end->y);

	int a = end.x - start.x;
	int b = end.y - start.y;

	double distance = sqrt(pow(a,2) + pow(b,2));

	printf("�� �� ������ ���� ���̴� %f �Դϴ�.", distance);

	return 0;
}