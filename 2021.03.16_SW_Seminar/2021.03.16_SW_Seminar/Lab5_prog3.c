#include <stdio.h>

int main(void) {

	char a;
	int i, j;

	printf("���ڸ� �Է��ϼ���:\n");
	scanf("%c",&a);

	for (i = 0; i < 7; i++) {
		for (j = 7; j > i; j--) {
			printf(" ");
		}
		for (j = 0; j < ((i+1)*2-1); j++) {
			printf("%c", a);
		}

		printf("\n");
	}


	return 0;
}