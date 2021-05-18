#include <stdio.h>
#include <math.h>

// #define INT_COORD �ּ�ó���ϸ� double��, �״�� �θ� int��
// #define INT_COORD

#ifdef INT_COORD
    typedef int COORD_TYPE;
#else
    typedef double COORD_TYPE;
#endif

typedef struct point {
    COORD_TYPE x;
    COORD_TYPE y;
} POINT;

double Distance(const POINT *start, const POINT *end);

int main(void)
{
    POINT pt1 = { 0, 0 };
    POINT pt2 = { 30, 40 };
    printf("�� �� ������ �Ÿ� : %f\n", Distance(&pt1, &pt2));

    return 0;
}

double Distance(const POINT *start, const POINT *end)
{
    COORD_TYPE dx = end->x - start->x;
    COORD_TYPE dy = end->y - start->y;
    return sqrt(dx*dx + dy*dy);
}