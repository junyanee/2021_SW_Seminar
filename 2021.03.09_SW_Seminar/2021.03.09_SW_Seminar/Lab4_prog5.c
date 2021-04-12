/* 다음 조건을 만족하는 프로그램을 작성하시오.

원금이 1, 000, 000인 경우, 예치 기간을 년 단위로 입력 받아 만기 시 총 금액을 출력
년단위 단리이자 = 원금 * 이율(4.5 %) * 년(예치기간)
만기 시 총 수령액(단리적용) = 원금(1 + 이율(4.5 %) * 년(예치기간)) */

#include <stdio.h>

int main(void) {

	
	int principal = 1000000, year;
	double interest = 0.045, total;

	printf("예치기간을 년단위로 입력하시오 :");
	scanf("%d", &year);
	
	total = principal * (1 + interest * year);
	
	printf("총금액은 %f입니다.\n", total);

	return 0;
}
