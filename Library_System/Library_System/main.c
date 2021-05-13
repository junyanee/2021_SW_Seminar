#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book {
	char name[40];
	char author[30];
	int price;
}BOOK;

void addBook(BOOK* books, int count);
void findBookByAuthor(BOOK* books);
void findBookByTitle(BOOK* books);
void orderByPrice(BOOK* books);
void showBook(BOOK* books, int count);
int compareByPrice(const void* book1, const void* book2);
int compareByName(const void* book1, const void* book2);
int compareByAuthor(const void* book1, const void* book2);

int count = 0;

int main(void) {

	int select = -1;
	BOOK* books[10] = { NULL };

	while (select != 5) {
		printf("도서 관리 프로그램\n");
		printf("1. 도서 입력\n");
		printf("2. 저자별 검색\n");
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
			addBook(books, count);
			showBook(books, count);
			break;

		case 2 :
			printf("저자별 검색을 선택하셨습니다.\n");
			findBookByAuthor(books);
			break;

		case 3 :
			printf("제목 검색을 선택하셨습니다.\n");
			findBookByTitle(books);

			break;
		case 4 :
			printf("가격 순으로 정렬을 선택하셨습니다.\n");
			orderByPrice(books);
			showBook(books, count);
			break;

		case 5 :
			printf("종료합니다.\n");
			break;

		default:
			printf("잘못된 입력입니다.\n");
		}
	}

	return 0;
}

void addBook(BOOK* book, int count) {
	char title[40] = { NULL };
	char author[30] = { NULL };
	int price = 0;

//	book[count] = malloc(sizeof(BOOK));
// 메모리할당해야함..

	printf("*** 새로운 도서를 추가합니다 ***\n");
	printf("제목을 입력하세요: \n");
	gets(title);
	strcpy(book->name, title);
	printf("저자를 입력하세요: \n");
	gets(author);
	strcpy(book->author, author);
	printf("가격을 입력하세요: \n");
	scanf("%d", &book->price);
	getchar();
	count++;

}
void showBook(const BOOK* books, int count) {
	for (int i = 0; i < count; i++) {
		printf("제목: %s\n", books[i].name);
		printf("저자: %s\n", books[i].author);
		printf("가격: %d원\n", books[i].price);
	}
}
void findBookByAuthor(BOOK* books) {
	char userInput[30] = { NULL };
	printf("검색하고자 하는 저자를 입력하세요: \n");
	gets(userInput);
	BOOK* authorP = (BOOK*)bsearch(userInput, books, 10, sizeof(BOOK), compareByAuthor);
}
void findBookByTitle(BOOK* books) {
	char userInput[30] = { NULL };
	printf("검색하고자 하는 제목을 입력하세요: \n");
	gets(userInput);
	BOOK* authorP = (BOOK*)bsearch(userInput, books, 10, sizeof(BOOK), compareByName);
}
void orderByPrice(BOOK* books) {
	qsort(books, 10, sizeof(BOOK), compareByPrice);
	showBook(books, sizeof(books));
}
int compareByPrice(const void* book1, const void* book2) {
	const BOOK* b1 = (const BOOK*)book1;
	const BOOK* b2 = (const BOOK*)book2;
	return b1->price - b2->price;
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