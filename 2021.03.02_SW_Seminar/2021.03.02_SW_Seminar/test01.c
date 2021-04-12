/* test01.c */
#include <stdio.h>

int main(void) 
{

		int age;
		double score;

		printf("나이를 입력하세요 : ");
		scanf_s("%d", &age);
		printf("입력하신 나이는 %d 입니다. \n", age);
		printf("점수를 입력하세요 : ");
		scanf_s("%lf", &score);
		printf("입력하신 점수는 %lf 입니다. \n", score);

	return 0;
}