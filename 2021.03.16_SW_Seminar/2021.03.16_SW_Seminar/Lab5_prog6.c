#include <stdio.h>

int g_result = 0;
int plusValue(int *p);
int minusValue(int *p);

int main(void) {

	int value = 0;
	int* p;
	p = value;
	char operator;

	printf("원하는 연산(+혹은 -)과 정수값을 입력하세요.\n더 이상 입력하지 않고자 할 때는 0을 입력하세요.\n");
	while (1) {
		scanf("%c", &operator);
		if (operator == '0') {
		break;
	}
		scanf("%d",&value);
		getchar();

		if (operator == '+') {
			plusValue(&value);
		}
		else if (operator == '-') {
			minusValue(&value);
		}
		
	}
	printf("%d\n",g_result);

	return 0;
}
int plusValue(int *p) {
	g_result += *p;
}
int minusValue(int *p) {
	g_result -= *p;
}