#include <stdio.h>

int add(int op1, int op2);
int sub(int op1, int op2);
int mul(int op1, int op2);
int div(int op1, int op2);
int main(void) {

	int select = -1;
	int operand1, operand2;
	int (*funP)(int, int) = NULL;
	printf("함수 번호와 계산할 값을 입력하세요: \n");
	scanf("%d %d %d", &select, &operand1, &operand2);
	switch (select)
	{
	case 0 :
		funP = add;
		printf("결과값 : %d\n", funP(operand1, operand2));
		break;
	case 1 :
		funP = sub;
		printf("결과값 : %d\n", funP(operand1, operand2));
		break;
	case 2 :
		funP = mul;
		printf("결과값 : %d\n", funP(operand1, operand2));
		break;
	case 3 :
		funP = div;
		printf("결과값 : %d\n", funP(operand1, operand2));
		break;
	default:
		printf("잘못된 입력입니다.\n");
		break;
	}
	return 0;
}
int add(int op1, int op2) {
	return op1 + op2;
}
int sub(int op1, int op2) {
	return op1 - op2;
}
int mul(int op1, int op2) {
	return op1 * op2;
}
int div(int op1, int op2) {
	if (op2 == 0) {
		printf("0으로 나눌 수 없습니다.");
		return 0;
	}
	else {
		return op1 / op2;
	}
	
}