#include <stdio.h>

int i, sum = 0;

int SumOfArray(const int*, int);

int main(void) {

	int arr[10] = {1,5,7,9,3,6,8,2,10,4};
	int* a = arr;

	printf("¹è¿­ÀÇ ÃÑÇÕ = %d\n", SumOfArray(arr, 10));

	return 0;
}

int SumOfArray(const int* a, int size) {
	int sum = 0;
	int i;

	for (i = 0; i < 10; i++) {
		sum = sum + *(a+i);
	}
	return sum;
}