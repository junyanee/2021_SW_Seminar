/* 1���� �� 3.156x107�ʿ� �ش��Ѵ�.3.156x107�� const  ���� yearTosec�� �����ϰ�,
���̸� �޼��� �Է� �޾� �� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. */

#include <stdio.h>

int main(void) {

	const double yearTosec = 3.156e7;
	int age;
	double ageTosec;

	printf("���̸� �Է��ϼ��� : ");
	scanf("%d", &age);
	
	ageTosec = age * yearTosec;
	printf("%e �ʸ� ��̽��ϴ�.", &ageTosec);


	return 0;
}