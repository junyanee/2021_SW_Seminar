/* 섭씨 온도를 입력 받은 후에 이를 화씨 온도로 변환하여 화면에 출력하는 프로그램을 작성하시오. 입력과 출력은 알아보기 쉽게 하시오. 
온도 변환 공식은 ( c 는 섭씨 온도, f 는 화씨 온도)f = 9.0 / 5.0 * c + 32.0; */

#include <stdio.h>

int main(void) {

	double c, f;

	printf("섭씨온도를 입력하세요 : \n");
	scanf("%lf", &c);

	f = 9.0 / 5.0 * c + 32.0;

	printf("변환된 화씨온도는 %f 입니다.\n", f);

	return 0;
}