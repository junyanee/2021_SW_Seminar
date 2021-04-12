#include <stdio.h>

int main(void) {

	char str[20];
	int len = 0;

	printf("문자열을 입력하세요: \n");
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