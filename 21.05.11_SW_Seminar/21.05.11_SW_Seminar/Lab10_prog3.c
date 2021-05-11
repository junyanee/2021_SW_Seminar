#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct font {
	char faceName[40];  // 폰트명
	unsigned int size;  // 폰트 크기
	int weight;         // 폰트 두께
} FONT;

int CompareByName(const void* e1, const void* e2);
int Compare(const void *cmp1, const void* cmp2);
void printFontInfo(const FONT* p);

int main(void) {

	FONT fonts[3] = { {"궁서", 10, 10}, {"돋음", 5, 5}, {"굴림", 3, 3} };
	qsort(fonts, 3, sizeof(FONT), CompareByName);
	// 굴림, 궁서, 돋음 순

	char userInput[40];
	FONT* fontP;

	int select = -1;
	while (1) {
		printf("메뉴를 선택하세요\n");
		printf("0. 종료\n");
		printf("1. 폰트 검색\n");
		scanf("%d", &select);
		getchar(); //엔터값 삭제

		switch (select)
		{
		case 0:
			return 0;
			break;

		case 1:
			printf("폰트 검색\n");
			printf("검색하고자 하는 폰트명을 입력하세요\n");
			gets(userInput);
			//	void bsearch(찾을 값의 주소, 찾을 대상이 되는 배열주소, 배열의 엘리먼트 개수, 배열크기, 비교함수);
			fontP = (FONT *) bsearch(userInput, fonts, 3, sizeof(FONT), CompareByName);
			printf("\n");
			printFontInfo(fontP);
			break;

		default:
			printf("잘못 입력하셨습니다.\n");
			break;
		}
	}
	return 0;
}

int CompareByName(const void* e1, const void* e2) {
	const FONT* p1 = (const FONT*)e1;
	const FONT* p2 = (const FONT*)e2;
	return strcmp(p1->faceName, p2->faceName);
}
int Compare(const void* cmp1, const void* cmp2) {
	return strcmp((char* ) cmp1, (char* ) cmp2);
}
void printFontInfo(const FONT* p) {
	printf("폰트명: %s\n", p->faceName);
	printf("폰트크기: %d\n", p->size);
	printf("폰트두께: %d\n", p->weight);
	printf("\n");
}