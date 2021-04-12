/* Ex04_13.c */
#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3;
    int result;

    result = a + b * c % 2;
    printf("result = %d\n", result);

    result = a > b || c > 0;
    printf("result = %d\n", result);

    result = a > b || c > 0 && b > c;
    printf("result = %d\n", result);

    result = ++a * b--;
    printf("result = %d\n", result);

    result = a = b = c;
    printf("result = %d\n", result);

    return 0;
}
