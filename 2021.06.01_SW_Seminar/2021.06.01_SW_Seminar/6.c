#include <stdio.h>

int fibonacci(int num);
int main(void) {

	int num;
	printf("������ �Է��ϼ���: (�Է� ���� ������ 10~30)");
	scanf("%d", &num);
	printf("%d", fibonacci(num));

	return 0;
}
int fibonacci(int num) {
	if (num == 0 || num == 1) {
		return num;
	}
	else {
		return fibonacci(num - 1) + fibonacci(num -2);
	}
}