#include <stdio.h>

int isLeapYear(int* year);

int main(void) {
	int input;
	printf("윤년인지 아닌지 확인하고 싶은 년도를 입력하세요: \n");
	scanf("%d", &input);

	if (isLeapYear(&input) == 1) {
		printf("윤년입니다\n");
	}
	else {
		printf("윤년이 아닙니다\n");
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