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
    printf("������ �Է��ϼ���: (�Է� ���� ������ 10~30): ");
    scanf("%d", &num1);

    printf("���� %d�� �ش��ϴ� �Ǻ���ġ ���� %d�Դϴ�.\n", num1, fib(num1));

    return 0;
}
