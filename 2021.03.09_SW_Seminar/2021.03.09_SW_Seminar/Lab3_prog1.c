/* Lab3 �ǽ�1 */
/* ASCII �ڵ� ���� �Է� �޾� �� ASCII �ڵ� ���� �ش��ϴ� ���ڸ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

   ������:
   ASCII �ڵ带 �Է��ϼ���: 65
   ASCII �ڵ� 65�� �ش��ϴ� ���� A �Դϴ�. */

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {

	int value;

	printf("ASCII �ڵ� ���� �Է��ϼ���: ");
	scanf("%d", &value);

	printf("ASCII �ڵ� %d�� �ش��ϴ� ���� %c�Դϴ�.\n", value, value);

	return 0;
}