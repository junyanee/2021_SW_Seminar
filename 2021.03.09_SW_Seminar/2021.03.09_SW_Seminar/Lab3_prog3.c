/* Lab3 실습3 */
/* int, unsigned int에 대해서 (최대값+1), (최소값-1)을 한 경우
어떤 값이 되는지 구하여 출력해 보시오. */

#include <stdio.h>
#include <limits.h>

int main(void) {

	printf("int 최대 : %d\nint 최대+1 : %d\nint 최소 : %d\nint 최소-1 : %d\n", INT_MAX, INT_MAX+1, INT_MIN, INT_MIN-1);

	return 0;
}