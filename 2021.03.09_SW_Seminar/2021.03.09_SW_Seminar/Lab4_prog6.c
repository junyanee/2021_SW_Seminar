/* �ǽ�5 ���α׷����� ���� ������ �����ϴ� ���α׷����� �����Ͽ� �ۼ��Ͻÿ�.
������ 1, 000, 000�� ���, ��ġ �Ⱓ�� �� ������ �Է� �޾� ���� �� �� �ݾ��� ���
���� �� �� ���ɾ�(��������) = ����(1 + ����(4.5 %))��(��ġ�Ⱓ)

�Լ� pow(a, b) = ab �̿�, #include <math.h> �ʿ� */

#include <stdio.h>
#include <math.h>

int main(void) {

	int principal = 1000000, year;
	double interest = 0.045, total;

	printf("��ġ�Ⱓ�� ������� �Է��Ͻÿ� :");
	scanf("%d", &year);

	total = principal * pow((1 + interest), year);

	printf("�ѱݾ��� %f�Դϴ�.\n", total);

	return 0;
}

