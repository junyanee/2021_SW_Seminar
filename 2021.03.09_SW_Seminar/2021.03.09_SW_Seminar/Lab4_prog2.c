/* 1년은 약 3.156x107초에 해당한다.3.156x107를 const  변수 yearTosec로 선언하고,
나이를 햇수로 입력 받아 초 단위로 출력하는 프로그램을 작성하시오. */

#include <stdio.h>

int main(void) {

	const double yearTosec = 3.156e7;
	int age;
	double ageTosec;

	printf("나이를 입력하세요 : ");
	scanf("%d", &age);
	
	ageTosec = age * yearTosec;
	printf("%e 초를 사셨습니다.", &ageTosec);


	return 0;
}