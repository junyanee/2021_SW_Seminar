/* test01.c */
#include <stdio.h>

int main(void) 
{

		int age;
		double score;

		printf("���̸� �Է��ϼ��� : ");
		scanf_s("%d", &age);
		printf("�Է��Ͻ� ���̴� %d �Դϴ�. \n", age);
		printf("������ �Է��ϼ��� : ");
		scanf_s("%lf", &score);
		printf("�Է��Ͻ� ������ %lf �Դϴ�. \n", score);

	return 0;
}