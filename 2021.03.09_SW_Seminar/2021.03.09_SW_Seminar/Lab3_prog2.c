/* Lab3 실습2 */
/* 문자를 입력받아 문자의 ASCII 코드 값을 출력하는 프로그램을 작성하시오.
   실행결과:
   문자를 입력하세요: A
   A에 해당하는 ASCII 코드 값은 65 입니다. */

#include <stdio.h>

int main(void) {

	char value;

	printf("문자를 입력하세요: ");
	scanf("%c", &value);

	printf("%c에 해당하는 ASCII 코드 값은 %d입니다.\n", value, value);

	return 0;
}
