#include <stdio.h>

void sumArray(int(*p)[3], int*, int);

int i, j, sum = 0;

int main(void) {

	int sumArr[5] = { 0, };
	int arr[5][3] = { {1,1,1}, {2,2,2}, {3,3,3}, {4,4,4}, {5,5,5} };

	sumArray(arr, sumArr, 5);

	return 0;
}
void sumArray(int(*p)[3], int* arr, int size) {
	for (i = 0; i < size; i++) {
		for (j = 0; j < 3; j++) {
			sum += p[i][j];
			arr[i] = sum;
		}
		printf(" %d번째 배열의 합: %d\n", i + 1, arr[i]);
		sum = 0;
	}
}