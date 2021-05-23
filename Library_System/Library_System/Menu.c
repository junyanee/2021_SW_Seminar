#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Menu.h"
#include "Book.h"


int printMenu() {
	int select = -1;
	printf(" ================================================\n");
	printf(" |  도서 관리 프로그램                          |\n");
	printf(" |  1. 도서 입력                                |\n");
	printf(" |  2. 저자 검색                                |\n");
	printf(" |  3. 제목 검색                                |\n");
	printf(" |  4. 가격 순으로 정렬	                        |\n");
	printf(" |  5. 전체 도서 정보 출력                      |\n");
	printf(" |  6. 종료                                     |\n");
	printf(" |                      authored by JunHyunPark |\n");
	printf(" ================================================\n");
	printf("\n");
	printf("메뉴를 선택하세요 : \n");
	scanf("%d", &select);
	getchar();
	return select;
}

int compareByPrice(const void* book1, const void* book2) {
	const BOOK* b1 = (const BOOK*)book1;
	const BOOK* b2 = (const BOOK*)book2;
	return -(b1->price - b2->price);
}

int compareByName(const void* book1, const void* book2) {
	const BOOK* b1 = (const BOOK*)book1;
	const BOOK* b2 = (const BOOK*)book2;
	return strcmp(b1->name, b2->name);
}

int compareByAuthor(const void* book1, const void* book2) {
	const BOOK* b1 = (const BOOK*)book1;
	const BOOK* b2 = (const BOOK*)book2;
	return strcmp(b1->author, b2->author);
}