#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 프로그램이 시작될 때 최대 저장 가능한 도서 정보의 개수를 입력 받아서 동적 메모리에 book 구조체 배열을 한꺼번에 할당

typedef struct book {
	char name[40];
	char author[30];
	int price;
}BOOK;

void addBook(BOOK* books, int* pc);
void findBookByAuthor(BOOK* books);
void findBookByTitle(BOOK* books);
void showBook(BOOK* books, int count);
int compareByPrice(const void* book1, const void* book2);
int compareByName(const void* book1, const void* book2);
int compareByAuthor(const void* book1, const void* book2);
void printBookInfo(const BOOK* p);
BOOK* allocateBooks(int numOfBook);

int count = 0;

int main(void) {

	int* pc = &count;
	int numOfBook = 0;
	int select = -1;

	BOOK* books = NULL;
	printf("등록할 책의 권수를 입력하세요: \n");
	scanf("%d", &numOfBook);
	while (getchar() != '\n');

	books = allocateBooks(numOfBook);
	if (books == NULL) {
		return -1;
	}

	while (1) {
		printf("도서 관리 프로그램\n");
		printf("1. 도서 입력\n");
		printf("2. 저자 검색\n");
		printf("3. 제목 검색\n");
		printf("4. 가격 순으로 정렬\n");
		printf("5. 전체 도서 정보 출력\n");
		printf("6. 종료\n");
		printf("\n");
		printf("메뉴를 선택하세요 : \n");
		scanf("%d", &select);
		getchar();

		switch (select)
		{
		case 1:
			printf("도서 입력을 선택하셨습니다.\n");
			printf("%d권까지 추가 저장할 수 있습니다.\n", numOfBook-count);
			if (count == numOfBook){
				printf("저장할 수 있는 공간이 다 찼습니다.\n");
			} else {
				addBook(books, pc);
			}
			break;

		case 2:
			printf("저자 검색을 선택하셨습니다.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByAuthor);
			findBookByAuthor(books);
			break;

		case 3:
			printf("제목 검색을 선택하셨습니다.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByName);
			findBookByTitle(books);
			break;

		case 4:
			printf("가격 순으로 정렬을 선택하셨습니다.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByPrice);
			showBook(books, count);
			break;

		case 5:
			showBook(books, count);

		case 6:
			printf("종료합니다.\n");
			return 0;
			break;

		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}

	free(books);
	books = NULL;

	return 0;
}

void addBook(BOOK* book, int* count) {
	char title[40] = { NULL };
	char author[30] = { NULL };
	int price = 0;

	printf("*** 새로운 도서를 추가합니다 ***\n");
	printf("제목을 입력하세요: \n");
	gets(title);
	strcpy(book[*count].name, title);
	printf("저자를 입력하세요: \n");
	gets(author);
	strcpy(book[*count].author, author);
	printf("가격을 입력하세요: \n");
	scanf("%d", &book[*count].price);
	getchar();
	(*count)++;

}
void showBook(const BOOK* books, int count) {
	printf(" === 전체 책 목록 === \n");
	for (int i = 0; i < count; i++) {
		printf("제목: %s\n", books[i].name);
		printf("저자: %s\n", books[i].author);
		printf("가격: %d원\n", books[i].price);
		printf("\n");
	}
}
void findBookByAuthor(BOOK* books) {
	printf("검색하고자 하는 저자를 입력하세요: \n");
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
	printf("검색하고자 하는 제목을 입력하세요: \n");
	BOOK titleKey;
	gets(titleKey.name);
	BOOK* titleP = (int*)bsearch(&titleKey, books, 10, sizeof(BOOK), compareByName);
		if (titleP != NULL) {
			printBookInfo(titleP);
		}
		else {
			printBookInfo(titleP);
			printf("해당 자료는 없습니다.");
		}
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

void printBookInfo(const BOOK* p) {
	printf("제목: %s\n", p->name);
	printf("저자: %s\n", p->author);
	printf("가격: %d원\n", p->price);
	printf("\n");
}

BOOK* allocateBooks(int numOfBook) {
	BOOK* result = NULL;
	result = (BOOK*)malloc(sizeof(BOOK) * numOfBook);
	if (result == NULL) {
		printf("동적 메모리 할당 실패\n");
	}
	else {
		memset(result, 0, sizeof(BOOK) * numOfBook);
	}
	return result;
}