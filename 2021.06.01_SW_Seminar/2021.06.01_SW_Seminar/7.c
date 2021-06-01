#include <stdio.h>

int add(int op1, int op2);
int sub(int op1, int op2);
int mul(int op1, int op2);
int div(int op1, int op2);
int main(void) {

	int select = -1;
	int operand1, operand2;
	int (*funP)(int, int) = NULL;
	printf("�Լ� ��ȣ�� ����� ���� �Է��ϼ���: \n");
	scanf("%d %d %d", &select, &operand1, &operand2);
	switch (select)
	{
	case 0 :
		funP = add;
		printf("����� : %d\n", funP(operand1, operand2));
		break;
	case 1 :
		funP = sub;
		printf("����� : %d\n", funP(operand1, operand2));
		break;
	case 2 :
		funP = mul;
		printf("����� : %d\n", funP(operand1, operand2));
		break;
	case 3 :
		funP = div;
		printf("����� : %d\n", funP(operand1, operand2));
		break;
	default:
		printf("�߸��� �Է��Դϴ�.\n");
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
		printf("0���� ���� �� �����ϴ�.");
		return 0;
	}
	else {
		return op1 / op2;
	}
	
}