#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "Menu.h"

// 프로그램이 시작될 때 최대 저장 가능한 도서 정보의 개수를 입력 받아서 동적 메모리에 book 구조체 배열을 한꺼번에 할당

int main(void) {

	int count = 0, numOfBook = 0;
	int* pc = &count;
	int* nb = &numOfBook;
	int reallocCount = 0;
	int* rc = &reallocCount;

	BOOK* books = NULL;

	printf("등록할 책의 권수를 입력하세요: \n");
	scanf("%d", &numOfBook);
	while (getchar() != '\n');

	books = allocateBooks(nb);

	if (books == NULL) {
		return -1;
	}
	
	while (1) {

		switch (printMenu())
		{
		case 1:
			printf("도서 입력을 선택하셨습니다.\n");
			printf("numofbook: %d, count: %d", numOfBook, count);
			printf("[%d권]까지 추가 저장할 수 있습니다.\n", numOfBook - count);
			if (count == numOfBook) {
				printf("=== 저장할 수 있는 공간이 다 찼습니다.=== \n");
				printf("추가 저장을 위해 [5권]의 메모리를 할당합니다.\n");
				numOfBook += 5;
				books = reallocateBooks(books, nb);
				addBook(books, pc);
			}
			else {
				addBook(books, pc);
			}
			break;

		case 2:
			printf("저자 검색을 선택하셨습니다.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByAuthor);
			findBookByAuthor(books, pc, nb);
			break;

		case 3:
			printf("제목 검색을 선택하셨습니다.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByName);
			findBookByTitle(books, pc, nb);
			break;

		case 4:
			printf("가격 순으로 정렬을 선택하셨습니다.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByPrice);
			showBook(books, pc);
			break;

		case 5:
			//qsort(books, numOfBook, sizeof(BOOK), compareByPrice);
			showBook(books, pc);
			break;



		case 0:
			printf("종료합니다.\n");
			freeMemory(books);
			return 0;
			break;

		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}

	return 0;
}
