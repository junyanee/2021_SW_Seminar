#include <stdio.h>

int isLeapYear(int* year);

int main(void) {
	int input;
	printf("�������� �ƴ��� Ȯ���ϰ� ���� �⵵�� �Է��ϼ���: \n");
	scanf("%d", &input);

	if (isLeapYear(&input) == 1) {
		printf("�����Դϴ�\n");
	}
	else {
		printf("������ �ƴմϴ�\n");
	}
	return 0;
}

int isLeapYear(int* year) {
	if ((*year % 4 == 0) && (*year % 100 != 0) || (*year % 400 == 0)) {
		return *year = 1;
	}
	else {
		return *year = 0;
	}
}