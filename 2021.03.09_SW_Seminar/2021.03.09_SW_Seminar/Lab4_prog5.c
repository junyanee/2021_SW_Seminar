/* ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ 1, 000, 000�� ���, ��ġ �Ⱓ�� �� ������ �Է� �޾� ���� �� �� �ݾ��� ���
����� �ܸ����� = ���� * ����(4.5 %) * ��(��ġ�Ⱓ)
���� �� �� ���ɾ�(�ܸ�����) = ����(1 + ����(4.5 %) * ��(��ġ�Ⱓ)) */

#include <stdio.h>

int main(void) {

	
	int principal = 1000000, year;
	double interest = 0.045, total;

	printf("��ġ�Ⱓ�� ������� �Է��Ͻÿ� :");
	scanf("%d", &year);
	
	total = principal * (1 + interest * year);
	
	printf("�ѱݾ��� %f�Դϴ�.\n", total);

	return 0;
}
