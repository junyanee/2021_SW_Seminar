#include <stdio.h>

int num = 10;
int arr[10];

void quickSortASC(int*, int, int);
void quickSortDESC(int*, int, int);

int main(void) {

	printf("정렬하고싶은 수를 10개 입력하세요:\n");
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	printf("1. 오름차순, 2. 내림차순 중 선택하세요: \n");
	int select;
	scanf("%d", &select);

	switch (select) {
	case 1:
		quickSortASC(arr, 0, num - 1);
		for (int i = 0; i < 10; i++) {
			printf("%d ", arr[i]);
		}
		break;
	case 2:
		quickSortDESC(arr, 0, num - 1);
		for (int i = 0; i < 10; i++) {
			printf("%d ", arr[i]);
		}
		break;
	}

	return 0;
}


void quickSortASC(int* data, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && arr[i] <= arr[key]) {
			i++;
		}
		while (j > start && arr[j] >= arr[key]) {
			j--;
		}
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[key];
			arr[key] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	quickSortASC(arr, start, j - 1);
	quickSortASC(arr, j + 1, end);
}
void quickSortDESC(int* arr, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && arr[i] >= arr[key]) {
			i++;
		}
		while (j > start && arr[j] <= arr[key]) {
			j--;
		}
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[key];
			arr[key] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	quickSortDESC(arr, start, j - 1);
	quickSortDESC(arr, j + 1, end);
}
