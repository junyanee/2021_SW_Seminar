#include <stdio.h>

int main(void) {
	// while�� ���
	int i = 1, sum = 0;

	while (i <= 100) {

		if (i % 7 != 0){
			sum += i;
		}
		
		i += 1;
	}
	printf("7�� ����� ������ 100������ �� ���� %d�Դϴ�.\n", sum);

	return 0;
}