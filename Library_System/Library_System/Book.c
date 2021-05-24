#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "Menu.h"

BOOK* allocateBooks(int* nb) {
	BOOK* result = NULL;
	result = (BOOK*)malloc(sizeof(BOOK) * (*nb));
	if (result == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
	}
	else {
		memset(result, 0, sizeof(BOOK) * (*nb));
	}
	return result;
}

BOOK* reallocateBooks(BOOK* books, int* nb) {

	BOOK* backUp = books;
	books = (BOOK*)realloc(books, sizeof(BOOK) * (*nb) * 2);
	if (books == NULL) {
		printf("�޸� ���Ҵ翡 �����߽��ϴ�. ���� ���·� �����մϴ�\n");
		books = backUp;
	}
	else {
		printf("�޸� ���Ҵ� ����\n");
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


	printf("===========���ο� ������ �߰��մϴ�===========\n");
	printf("������ �Է��ϼ���: ");
	gets(title);
	strcpy(book[*pc].name, title);
	printf("���ڸ� �Է��ϼ���: ");
	gets(author);
	strcpy(book[*pc].author, author);
	printf("������ �Է��ϼ���: ");
	scanf("%d", &book[*pc].price);
	getchar();
	(*pc)++;
}

void showBook(const BOOK* books, int* pc) {
	printf("===========��ü å ���===========\n");
	for (int i = 0; i < *pc; i++) {
		printf("%d��\n", i+1);
		printf("����: %s\n", books[i].name);
		printf("����: %s\n", books[i].author);
		printf("����: %d��\n", books[i].price);
		printf("\n");
	}
	printf("==================================\n");
}

void findBookByAuthor(BOOK* books) {
	int modifySelect = -1;
	printf("�˻��ϰ��� �ϴ� ���ڸ� �Է��ϼ���: ");
	BOOK authorKey;
	gets(authorKey.author);
	BOOK* authorP = (int*)bsearch(&authorKey, books, 10, sizeof(BOOK), compareByAuthor);
	if (authorP != NULL) {
		printBookInfo(authorP);
		printf("�ش� �ڷḦ ���� Ȥ�� �����Ͻðڽ��ϱ�?\n");
		printf("1. ����     2. ����     3. ������");
		scanf("%d", &modifySelect);
		getchar();
		switch (modifySelect)
		{
		case 1:
			printf("===å ������ �����մϴ�.===\n");
			printf("������ �Է��ϼ���: ");
			gets(authorP->name);
			printf("���ڸ� �Է��ϼ���: ");
			gets(authorP->author);
			printf("������ �Է��ϼ���: ");
			scanf("%d", &authorP->price);
			getchar();
			break;
		case 2:
			printf("===å ������ �����մϴ�.===\n");
			break;
		case 3: 
			printf("�޴��� ���ư��ϴ�.\n");
			break;
		default:
			printf("�߸��� �Է��Դϴ�. �޴��� ���ư��ϴ�.\n");
			break;
		}

	}
	else {
		printf("�ش� �ڷ�� �����ϴ�.\n");
	}
}

void findBookByTitle(BOOK* books) {
	int modifySelect = -1;
	printf("�˻��ϰ��� �ϴ� ������ �Է��ϼ���: ");
	BOOK titleKey;
	gets(titleKey.name);
	BOOK* titleP = (int*)bsearch(&titleKey, books, 10, sizeof(BOOK), compareByName);
	if (titleP != NULL) {
		printBookInfo(titleP);
		printf("�ش� �ڷḦ �����Ͻðڽ��ϱ�?\n");
		printf("1. ����     2. ������");
		scanf("%d", &modifySelect);
		getchar();
		switch (modifySelect)
		{
		case 1:
			printf("===å ������ �����մϴ�.===\n");
			printf("������ �Է��ϼ���: ");
			gets(titleP->name);
			printf("���ڸ� �Է��ϼ���: ");
			gets(titleP->author);
			printf("������ �Է��ϼ���: ");
			scanf("%d", &titleP->price);
			getchar();
			break;
		case 2:
			printf("�޴��� ���ư��ϴ�.\n");
			break;
		default:
			printf("�߸��� �Է��Դϴ�. �޴��� ���ư��ϴ�.\n");
			break;
		}
	}
	else {
		printf("�ش� �ڷ�� �����ϴ�.");
	}
}

void printBookInfo(const BOOK* p) {
	printf("==================================\n");
	printf("����: %s\n", p->name);
	printf("����: %s\n", p->author);
	printf("����: %d��\n", p->price);
	printf("==================================\n");
	printf("\n");
}