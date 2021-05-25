#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "Menu.h"

BOOK* allocateBooks(int* nb) {
	BOOK* result = NULL;
	result = (BOOK*)malloc(sizeof(BOOK) * (*nb));
	if (result == NULL) {
		printf("동적 메모리 할당 실패\n");
	}
	else {
		memset(result, 0, sizeof(BOOK) * (*nb));
	}
	return result;
}

BOOK* reallocateBooks(BOOK* books, int* nb) {

	BOOK* backUp = books;
	books = (BOOK*)realloc(books, sizeof(BOOK) * ((*nb) + 5));
	if (books == NULL) {
		printf("메모리 재할당에 실패했습니다. 원래 상태로 복구합니다\n");
		books = backUp;
	}
	else {
		printf("메모리 재할당 성공\n");
	}
	return books;
}

int freeMemory(BOOK* books) {
	free(books);
	books = NULL;
	return 0;
}

void addBook(BOOK* book, int* pc) {
	char title[40] = { NULL };
	char author[30] = { NULL };
	int price = 0;


	printf("===========새로운 도서를 추가합니다===========\n");
	printf("제목을 입력하세요: ");
	gets(title);
	strcpy(book[*pc].name, title);
	printf("저자를 입력하세요: ");
	gets(author);
	strcpy(book[*pc].author, author);
	printf("가격을 입력하세요: ");
	scanf("%d", &book[*pc].price);
	getchar();
	(*pc)++;
}

void showBook(const BOOK* books, int* pc) {
	printf("===========전체 책 목록===========\n");
	for (int i = 0; i < *pc; i++) {
		printf("%d번\n", i+1);
		printf("제목: %s\n", books[i].name);
		printf("저자: %s\n", books[i].author);
		printf("가격: %d원\n", books[i].price);
		printf("\n");
	}
	printf("==================================\n");
}

void findBookByAuthor(BOOK* books, int *pc, int *nb) {
	int modifySelect = -1;
	printf("검색하고자 하는 저자를 입력하세요: ");
	BOOK authorKey;
	gets(authorKey.author);
	BOOK* authorP = (int*)bsearch(&authorKey, books, *nb, sizeof(BOOK), compareByAuthor);
	if (authorP != NULL) {
		printBookInfo(authorP);
		printf("해당 자료를 수정 혹은 삭제하시겠습니까?\n");
		printf("1. 수정     2. 삭제     3. 나가기");
		scanf("%d", &modifySelect);
		getchar();
		switch (modifySelect)
		{
		case 1:
			printf("===책 정보를 수정합니다.===\n");
			printf("제목을 입력하세요: ");
			gets(authorP->name);
			printf("저자를 입력하세요: ");
			gets(authorP->author);
			printf("가격을 입력하세요: ");
			scanf("%d", &authorP->price);
			getchar();
			break;
		case 2:
			printf("===책 정보를 삭제합니다.===\n");
		//	memset(authorP, NULL, sizeof(BOOK));
		//	(*nb)--;
		//	(*pc)--;
			break;
		case 3: 
			printf("메뉴로 돌아갑니다.\n");
			break;
		default:
			printf("잘못된 입력입니다. 메뉴로 돌아갑니다.\n");
			break;
		}

	}
	else {
		printf("해당 자료는 없습니다.\n");
	}
}

void findBookByTitle(BOOK* books, int* pc, int* nb) {
	int modifySelect = -1;
	printf("검색하고자 하는 제목을 입력하세요: ");
	BOOK titleKey;
	gets(titleKey.name);
	BOOK* titleP = (int*)bsearch(&titleKey, books, *nb, sizeof(BOOK), compareByName);
	if (titleP != NULL) {
		printBookInfo(titleP);
		printf("해당 자료를 수정하시겠습니까?\n");
		printf("1. 수정     2. 삭제     3. 나가기");
		scanf("%d", &modifySelect);
		getchar();
		switch (modifySelect)
		{
		case 1:
			printf("===책 정보를 수정합니다.===\n");
			printf("제목을 입력하세요: ");
			gets(titleP->name);
			printf("저자를 입력하세요: ");
			gets(titleP->author);
			printf("가격을 입력하세요: ");
			scanf("%d", &titleP->price);
			getchar();
			break;
		case 2:
			// 배열의 인덱스를 가져와서 i에 저장
			// i이후의 배열에서 memcpy(i, i+1)
			printf("===책 정보를 삭제합니다.===\n");
			//memset(titleP, NULL, sizeof(BOOK));
			//(*nb)--;
			//(*pc)--;
			//int i, j = 0; //ㅇㅇ
			//i = titleP - books; //ㅇㅇ 삭제하고자 하는 인덱스
			//printf("%d", i); //ㅇㅇ
			//for (int j = i; j < (*pc) -1; j++) { //ㅇㅇ
			//	strcpy(books[i].name, books[i + 1].name);
			//	strcpy(books[i].author, books[i + 1].author);
			//	books[i].price = books[i + 1].price;
			//	memcpy(&books[i],&books[i+1], sizeof(BOOK)); //ㅇㅇ

		//	for (int i = titleP - books; i < sizeof(books) / sizeof(BOOK) -2; i++) {
		//		//memcpy(&books[i], &books[i + 1], sizeof(BOOK));
		//			strcpy(books[i].name, books[i + 1].name);
		//		strcpy(books[i].author, books[i + 1].author);
		//		books[i].price = books[i + 1].price;
		//	}

			for (int i = 0; i < sizeof(books) / sizeof(BOOK); i++) {
				if (strcmp(titleP->name, books[i].name) == 0) {
					(*pc)--;
					printf("삭제완료");

					if (i!= sizeof(books) / sizeof(BOOK) - 1) {
						for (int j = i; j < sizeof(books) / sizeof(BOOK); j++) {
							strcpy(books[i].name, books[i + 1].name);
							strcpy(books[i].author, books[i + 1].author);
							books[i].price = books[i + 1].price;
						}
						*books[sizeof(books) / sizeof(BOOK) - 1].name = NULL;
						*books[sizeof(books) / sizeof(BOOK) - 1].author = NULL;
					}
				}
			}
			(*pc)--;
			break;
		case 3:
			printf("메뉴로 돌아갑니다.\n");
			break;
		default:
			printf("잘못된 입력입니다. 메뉴로 돌아갑니다.\n");
			break;
		}
	}
	else {
		printf("해당 자료는 없습니다.");
	}
}

void printBookInfo(const BOOK* p) {
	printf("==================================\n");
	printf("제목: %s\n", p->name);
	printf("저자: %s\n", p->author);
	printf("가격: %d원\n", p->price);
	printf("==================================\n");
	printf("\n");
}