#include <stdio.h>

int main(void) {

	char str[20];
	int len = 0;

	printf("���ڿ��� �Է��ϼ���: \n");
	scanf("%s", str);

	while (str[len] != '\0')
		len++;
	len--;
	while (len > -1) {
		printf("%c", str[len]);
		len--;
	}
	return 0;
}