#include <stdio.h>

int main(void) {
	// for문 사용
	int i, sum=0;
	for (i = 1; i <= 100; i++) {
		
		if (i % 7 != 0) {
			sum += i;
		}
	}
	printf("7의 배수를 제외한 100까지의 총 합은 %d입니다.\n", sum);

	return 0;
}