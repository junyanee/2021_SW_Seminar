#include <stdio.h>

int main(void) {
	// while문 사용
	int i = 1, sum = 0;

	while (i <= 100) {

		if (i % 7 != 0){
			sum += i;
		}
		
		i += 1;
	}
	printf("7의 배수를 제외한 100까지의 총 합은 %d입니다.\n", sum);

	return 0;
}