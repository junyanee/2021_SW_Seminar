#include <stdio.h>
#include <string.h>

typedef struct book {
	char name[20];
	char author[30];
	int price;
	int bookCount;
}BOOK;

void addBook(BOOK*);
void showBook(BOOK*);

int main(void) {

	int select = 0;
	BOOK bookshelf[10];
	BOOK* p = bookshelf;

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

		switch (select)
		{
		case 1 :
			printf("도서 입력을 선택하셨습니다.\n");
			addBook(p);
			showBook(p);
			break;

		case 2 :
			printf("저자별 검색을 선택하셨습니다.\n");

			break;
		case 3 :
			printf("제목 검색을 선택하셨습니다.\n");

			break;
		case 4 :
			printf("가격 순으로 정렬을 선택하셨습니다.\n");

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

void addBook(BOOK* book) {
	printf("*** 새로운 도서를 추가합니다 ***\n");

	printf("제목을 입력하세요: \n");
	scanf("%s", book->name);
	printf("저자를 입력하세요: \n");
	scanf("%s", book->author);
	printf("가격을 입력하세요: \n");
	scanf("%d", book->price);

}
void showBook(BOOK* book) {
	for (int i = 0; i < 10; i++) {
		printf("제목: %s\n", book->name);
		printf("저자: %s\n", book->author);
		printf("가격: %d 원\n", book->price);
	}
}