#include <stdio.h>

struct Point2D {
    int x;
    int y;
};

void movePoint2D(struct Point2D* p1, int offsetX, int offsetY)
{
    p1->x += offsetX;
    p1->y += offsetY;
}

int main()
{
    struct Point2D p1;
    int offsetX, offsetY;

    printf("점의 x, y 좌표, 이동할 x, y 값을 순서대로 입력하시오:\n");
    scanf("%d %d %d %d", &p1.x, &p1.y, &offsetX, &offsetY);

    movePoint2D(&p1, offsetX, offsetY);

    printf("이동한 점의 좌표는 (%d, %d) 입니다.\n", p1.x, p1.y);

    return 0;
}
