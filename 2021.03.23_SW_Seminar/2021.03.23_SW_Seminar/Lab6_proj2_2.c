#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
int GetMin(const int*, int);
int GetMax(const int*, int);
int RnumberGen(int*, int, int);
int main(void) {

    int arr[MAXSIZE];
    int i;
    int* p = arr;

    for (int i = 0; i < 10; i++) {
        arr[i] = RnumberGen(arr, MAXSIZE, 200);
    }

    printf("최소값: %d\n", GetMin(arr, MAXSIZE));
    printf("최대값: %d\n", GetMax(arr, MAXSIZE));
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
int RnumberGen(int* A, int size, int range) {
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        A[i] = rand() % range + 1;
    }
}