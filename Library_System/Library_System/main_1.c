#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 구조체 포인터 배열 사용, 최대 10개의 도서 정보를 저장

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

int count = 0;

int main(void) {

	int select = -1;
	int* pc = &count;
	
	BOOK* books[10] = { NULL };
	for (int i = 0; i < sizeof(books)/sizeof(BOOK); i++) {
		books[i] = malloc(sizeof(BOOK));
		memset(books[i], 0, sizeof(BOOK));
	}

	while (1) {
		printf("도서 관리 프로그램\n");
		printf("1. 도서 입력\n");
		printf("2. 저자 검색\n");
		printf("3. 제목 검색\n");
		printf("4. 가격 순으로 정렬\n");
		printf("5. 종료\n");
		printf("\n");
		printf("메뉴를 선택하세요 : \n");
		scanf("%d", &select);
		getchar();

		switch (select)
		{
		case 1 :
			printf("도서 입력을 선택하셨습니다.\n");
			if (count == 10) {
				printf("저장할 수 있는 공간이 다 찼습니다.\n");
			}
			else {
				addBook(books, pc);
				showBook(books, count);
			}
			break;

		case 2 :
			printf("저자 검색을 선택하셨습니다.\n");
			qsort(books, count, sizeof(BOOK), compareByAuthor);
			findBookByAuthor(books);
			break;

		case 3 :
			printf("제목 검색을 선택하셨습니다.\n");
			qsort(books, count, sizeof(BOOK), compareByName);
			findBookByTitle(books);
			break;

		case 4 :
			printf("가격 순으로 정렬을 선택하셨습니다.\n");
			qsort(books, count, sizeof(BOOK), compareByPrice);
			showBook(books, count);
			break;

		case 5 :
			printf("종료합니다.\n");
			for (int i = 0; i < 10; i++) {
				free(books[i]);
				books[i] = NULL;
			}
			return 0;
			break;

		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
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
	BOOK* authorP = (int*)bsearch(&authorKey, books, count, sizeof(BOOK), compareByAuthor);
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
	BOOK* titleP = (int*)bsearch(&titleKey, books, count, sizeof(BOOK), compareByName);
	if (titleP != NULL) {
		printBookInfo(titleP);
	}
	else {
		printf("해당 자료는 없습니다.\n");
	}
}

int compareByPrice(const void* book1, const void* book2) {
	const BOOK* b1 = (const BOOK*)book1;
	const BOOK* b2 = (const BOOK*)book2;
	return - (b1->price - b2->price);
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