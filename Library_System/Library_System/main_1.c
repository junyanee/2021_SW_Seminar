#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ����ü ������ �迭 ���, �ִ� 10���� ���� ������ ����

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
		printf("���� ���� ���α׷�\n");
		printf("1. ���� �Է�\n");
		printf("2. ���� �˻�\n");
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
			if (count == 10) {
				printf("������ �� �ִ� ������ �� á���ϴ�.\n");
			}
			else {
				addBook(books, pc);
				showBook(books, count);
			}
			break;

		case 2 :
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");
			qsort(books, count, sizeof(BOOK), compareByAuthor);
			findBookByAuthor(books);
			break;

		case 3 :
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");
			qsort(books, count, sizeof(BOOK), compareByName);
			findBookByTitle(books);
			break;

		case 4 :
			printf("���� ������ ������ �����ϼ̽��ϴ�.\n");
			qsort(books, count, sizeof(BOOK), compareByPrice);
			showBook(books, count);
			break;

		case 5 :
			printf("�����մϴ�.\n");
			for (int i = 0; i < 10; i++) {
				free(books[i]);
				books[i] = NULL;
			}
			return 0;
			break;

		default:
			printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
	}
	return 0;
}

void addBook(BOOK* book, int* count) {
	char title[40] = { NULL };
	char author[30] = { NULL };
	int price = 0;

	printf("*** ���ο� ������ �߰��մϴ� ***\n");
	printf("������ �Է��ϼ���: \n");
	gets(title);
	strcpy(book[*count].name, title);
	printf("���ڸ� �Է��ϼ���: \n");
	gets(author);
	strcpy(book[*count].author, author);
	printf("������ �Է��ϼ���: \n");
	scanf("%d", &book[*count].price);
	getchar();
	(*count)++;

}
void showBook(const BOOK* books, int count) {
	printf(" === ��ü å ��� === \n");
	for (int i = 0; i < count; i++) {
		printf("����: %s\n", books[i].name);
		printf("����: %s\n", books[i].author);
		printf("����: %d��\n", books[i].price);
		printf("\n");
	}
}

void findBookByAuthor(BOOK* books) {
	printf("�˻��ϰ��� �ϴ� ���ڸ� �Է��ϼ���: \n");
	BOOK authorKey;
	gets(authorKey.author);
	BOOK* authorP = (int*)bsearch(&authorKey, books, count, sizeof(BOOK), compareByAuthor);
	if (authorP != NULL) {
		printBookInfo(authorP);
	}
	else {
		printf("�ش� �ڷ�� �����ϴ�.\n");
	}
}

void findBookByTitle(BOOK* books) {
	printf("�˻��ϰ��� �ϴ� ������ �Է��ϼ���: \n");
	BOOK titleKey;
	gets(titleKey.name);
	BOOK* titleP = (int*)bsearch(&titleKey, books, count, sizeof(BOOK), compareByName);
	if (titleP != NULL) {
		printBookInfo(titleP);
	}
	else {
		printf("�ش� �ڷ�� �����ϴ�.\n");
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
	printf("����: %s\n", p->name);
	printf("����: %s\n", p->author);
	printf("����: %d��\n", p->price);
	printf("\n");
}