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

void findBookByAuthor(BOOK* books) {
	printf("검색하고자 하는 저자를 입력하세요: ");
	BOOK authorKey;
	gets(authorKey.author);
	BOOK* authorP = (int*)bsearch(&authorKey, books, 10, sizeof(BOOK), compareByAuthor);
	if (authorP != NULL) {
		printBookInfo(authorP);
	}
	else {
		printf("해당 자료는 없습니다.\n");
	}
}

void findBookByTitle(BOOK* books) {
	printf("검색하고자 하는 제목을 입력하세요: ");
	BOOK titleKey;
	gets(titleKey.name);
	BOOK* titleP = (int*)bsearch(&titleKey, books, 10, sizeof(BOOK), compareByName);
	if (titleP != NULL) {
		printBookInfo(titleP);
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

