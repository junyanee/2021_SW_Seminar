#include <stdio.h>

int main(void) {
	// do_while�� ���
	int i = 1, sum = 0;

	do {
		if (i % 7 != 0) {
			sum += i;
		}
		i += 1;
	} while (i <= 100);

	printf("7�� ����� ������ 100������ �� ���� %d�Դϴ�.\n", sum);

	return 0;
}