#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book {
	char name[40];
	char author[30];
	int price;
}BOOK;

void addBook(BOOK* books);
void findBookByAuthor(BOOK* books);
void findBookByTitle(BOOK* books);
void orderByPrice(BOOK* books);
void showBook(BOOK* books, int count);
int compareByPrice(const void* book1, const void* book2);
int compareByName(const void* book1, const void* book2);
int compareByAuthor(const void* book1, const void* book2);


int main(void) {

	int select = -1;
	BOOK* books[10] = { NULL };
	int count = 0;

	while (select != 5) {
		printf("���� ���� ���α׷�\n");
		printf("1. ���� �Է�\n");
		printf("2. ���ں� �˻�\n");
		printf("3. ���� �˻�\n");
		printf("4. ���� ������ ����\n");
		printf("5. ����\n");
		printf("\n");
		printf("�޴��� �����ϼ��� : \n");
		scanf("%d", &select);
		getchar();

		switch (select)
		{
		case 1 :
			printf("���� �Է��� �����ϼ̽��ϴ�.\n");
			addBook(books);
			showBook(books, sizeof(books));
			break;

		case 2 :
			printf("���ں� �˻��� �����ϼ̽��ϴ�.\n");
			break;
		case 3 :
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");

			break;
		case 4 :
			printf("���� ������ ������ �����ϼ̽��ϴ�.\n");
			orderByPrice(books);
			showBook(books, sizeof(books));
			break;
		case 5 :
			printf("�����մϴ�.\n");
			break;
		default:
			printf("�߸��� �Է��Դϴ�.\n");
		}
	}

	return 0;
}

void addBook(BOOK* book) {
	char title[40] = { NULL };
	char author[30] = { NULL };
	int price = 0;

	printf("*** ���ο� ������ �߰��մϴ� ***\n");
	printf("������ �Է��ϼ���: \n");
	gets(title);
	strcpy(book->name, title);
	printf("���ڸ� �Է��ϼ���: \n");
	gets(author);
	strcpy(book->author, author);
	printf("������ �Է��ϼ���: \n");
	scanf("%d", &book->price);
	getchar();

}
void showBook(const BOOK* books, int count) {
	for (int i = 0; i < count; i++) {
		printf("����: %s\n", books[i].name);
		printf("����: %s\n", books[i].author);
		printf("����: %d��\n", books[i].price);
	}
}
void findBookByAuthor(BOOK* books) {
	char userInput[30] = { NULL };
	printf("�˻��ϰ��� �ϴ� ���ڸ� �Է��ϼ���: \n");
	gets(userInput);
	BOOK* authorP = (BOOK*)bsearch(userInput, books, 10, sizeof(BOOK), compareByAuthor);
}
void findBookByTitle(BOOK* books) {
	char userInput[30] = { NULL };
	printf("�˻��ϰ��� �ϴ� ������ �Է��ϼ���: \n");
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