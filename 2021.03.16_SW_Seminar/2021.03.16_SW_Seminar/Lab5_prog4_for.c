#include <stdio.h>

int main(void) {
	// for�� ���
	int i, sum=0;
	for (i = 1; i <= 100; i++) {
		
		if (i % 7 != 0) {
			sum += i;
		}
	}
	printf("7�� ����� ������ 100������ �� ���� %d�Դϴ�.\n", sum);

	return 0;
}