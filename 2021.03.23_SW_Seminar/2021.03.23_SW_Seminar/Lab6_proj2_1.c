#include <stdio.h>

int GetMin(const int*, int);
int GetMax(const int*, int);

int main(void) {

    int arr[10];
    int i;
    int *p = arr;

    for (int i = 0; i < 10; i++) {
        printf("%d 번째 값을 입력하세요:\n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("최소값: %d\n", GetMin(arr, 10)); 
    printf("최대값: %d\n", GetMax(arr, 10));

	return 0;
}
int GetMax(const int* arr, int cnt) {
    int max = arr[0];
    for (int i = 0; i < cnt; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int GetMin(const int* arr, int cnt) {
    int min = arr[0];
    for (int i = 0; i < cnt; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}