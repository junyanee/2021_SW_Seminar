#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book {
	char name[40];
	char author[30];
	int price;
}BOOK;

void addBook(BOOK* books, int* pc);
void findBookByAuthor(BOOK* books);
void findBookByTitle(BOOK* books);
void orderByPrice(BOOK* books, int count);
void showBook(BOOK* books, int count);
int compareByPrice(const void* book1, const void* book2);
int compareByName(const void* book1, const void* book2);
int compareByAuthor(const void* book1, const void* book2);
void printBookInfo(const BOOK* p);
void orderByName(BOOK* books, int count);
void orderByAuthor(BOOK* books, int count);

int count = 0;

int main(void) {

	int select = -1;
	int* pc = &count;

	BOOK* books[10] = { NULL };

	for (int i = 0; i < sizeof(books) / sizeof(BOOK*); i++) {
		books[i] = malloc(sizeof(BOOK));
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
			addBook(books, pc);
			showBook(books, count);
			break;

		case 2 :
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");
			orderByAuthor(books, count);
			findBookByAuthor(books);
			break;

		case 3 :
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");
			orderByName(books, count);
			findBookByTitle(books);

			break;
		case 4 :
			printf("���� ������ ������ �����ϼ̽��ϴ�.\n");
			orderByPrice(books, count);
			showBook(books, count);
			break;

		case 5 :
			printf("�����մϴ�.\n");
			return 0;
			break;

		// for debug
		case 6 :
			showBook(books, count);
			break;

		// for debug
		case 7:
			orderByAuthor(books, count); //��������
			break;
		// for debug
		case 8:
			orderByName(books, count);
			break;
		default:
			printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
	}

	for (int i = 0; i < sizeof(books) / sizeof(BOOK*); i++) {
		free(books[i]);
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
	char userInput[30] = { NULL };
	BOOK authorKey;
	printf("�˻��ϰ��� �ϴ� ���ڸ� �Է��ϼ���: \n");
	gets(authorKey.author);
	BOOK* authorP = (BOOK*)bsearch(authorKey.author, books, 10, sizeof(BOOK), compareByAuthor);
	puts(authorKey.author);
	if (authorP != NULL) {
		printBookInfo(authorP);
	}
	else {
		printBookInfo(authorP);
		printf("�ش� �ڷ�� �����ϴ�.");
	}

/*	for (int i = 0; i < count; i++) {
		if (strcmp(userInput, books[i].author) == 0) {
			printf("����: %s\n", books[i].name);
			printf("����: %s\n", books[i].author);
			printf("����: %d��\n", books[i].price);
			printf("\n");
		}
	}*/
	
}
void findBookByTitle(BOOK* books) {
	char userInput[30] = { NULL };
	printf("�˻��ϰ��� �ϴ� ������ �Է��ϼ���: \n");
	gets(userInput);
	// void bsearch(ã�� ���� �ּ�, ã�� ����� �Ǵ� �迭�ּ�, �迭�� ������Ʈ ����, �迭ũ��, ���Լ�);
/*	for (int i = 0; i < count; i++) {
		if (strcmp(userInput, books[i].name) == 0) {
			printf("����: %s\n", books[i].name);
			printf("����: %s\n", books[i].author);
			printf("����: %d��\n", books[i].price);
			printf("\n");
		}
	}*/
	
	BOOK* titleP= (BOOK*)bsearch(userInput, books, 10, sizeof(BOOK), compareByName);
		if (titleP != NULL) {
			printBookInfo(titleP);
		}
		else {
			printBookInfo(titleP);
			printf("�ش� �ڷ�� �����ϴ�.");
		}
}

void orderByPrice(BOOK* books, int count) {
	qsort(books, count, sizeof(BOOK), compareByPrice);
}

void orderByName(BOOK* books, int count) {
	qsort(books, count, sizeof(BOOK), compareByName);
}

void orderByAuthor(BOOK* books, int count) {
	qsort(books, count, sizeof(BOOK), compareByAuthor);
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