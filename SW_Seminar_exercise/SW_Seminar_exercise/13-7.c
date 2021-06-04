#include <stdio.h>

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int num1;
    printf("정수를 입력하세요: (입력 값의 범위는 10~30): ");
    scanf("%d", &num1);

    printf("정수 %d에 해당하는 피보나치 수는 %d입니다.\n", num1, fib(num1));

    return 0;
}
