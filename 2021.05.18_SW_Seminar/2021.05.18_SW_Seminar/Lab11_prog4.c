
#include <stdio.h>
#include <string.h>

#define ALGORITHM 1
#define COUNT 5
#define LENGTH 16

void printStrings(const char(*arr)[LENGTH], int size);
void selectionSort(char(*arr)[LENGTH], int size);
void quickSort(char(*arr)[LENGTH], int size);

int main(void)
{
    char arr[COUNT][LENGTH] = {
        "watermelon", "strawberry", "kiwi", "mango", "banana",
    };

    printf("정렬 전 ");
    printStrings(arr, COUNT);

#if ALGORITHM == 1
    selectionSort(arr, COUNT);
#elif ALGORITHM == 2
    quickSort(arr, COUNT);
#endif

    printf("정렬 후 ");
    printStrings(arr, COUNT);

    return 0;
}

void printStrings(const char(*arr)[LENGTH], int size)
{
    int i;

    printf("문자열 배열 : ");
    for (i = 0; i < size; i++)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

void selectionSort(char(*arr)[LENGTH], int size) {
	int i, j, min;
	char temp[LENGTH] = "";

	for (i = 0; size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (strcmp(arr[j], arr[min]) < 0) {
				min = j;
			}
		}
		strcpy(temp, arr[min]);
		strcpy(arr[min], arr[i]);
		strcpy(arr[i], temp);
	}
}

void quickSort(char(*arr)[LENGTH], int size)
{
    int left, right;
    char key[LENGTH];
    char temp[LENGTH];

    if (size <= 1)
        return;

    strcpy(key, arr[0]);
    left = 0;
    right = size;
    while (1)
    {
        while (strcmp(arr[++left], key) < 0);
        while (strcmp(arr[--right], key) > 0);
        if (left >= right)
            break;

        strcpy(temp, arr[left]);
        strcpy(arr[left], arr[right]);
        strcpy(arr[right], temp);
    }
    strcpy(temp, arr[right]);
    strcpy(arr[right], arr[0]);
    strcpy(arr[0], temp);

    quickSort(arr, right);
    quickSort(arr + right + 1, size - right - 1);
}