/* Lab3 �ǽ�2 */
/* ���ڸ� �Է¹޾� ������ ASCII �ڵ� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
   ������:
   ���ڸ� �Է��ϼ���: A
   A�� �ش��ϴ� ASCII �ڵ� ���� 65 �Դϴ�. */

#include <stdio.h>

int main(void) {

	char value;

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%c", &value);

	printf("%c�� �ش��ϴ� ASCII �ڵ� ���� %d�Դϴ�.\n", value, value);

	return 0;
}
