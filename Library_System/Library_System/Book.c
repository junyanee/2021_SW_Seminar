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
	books = (BOOK*)realloc(books, sizeof(BOOK) * ((*nb) + 5));
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

void findBookByAuthor(BOOK* books, int *pc, int *nb) {
	int modifySelect = -1;
	printf("�˻��ϰ��� �ϴ� ���ڸ� �Է��ϼ���: ");
	BOOK authorKey;
	gets(authorKey.author);
	BOOK* authorP = (int*)bsearch(&authorKey, books, *nb, sizeof(BOOK), compareByAuthor);
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
		//	memset(authorP, NULL, sizeof(BOOK));
		//	(*nb)--;
		//	(*pc)--;
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

void findBookByTitle(BOOK* books, int* pc, int* nb) {
	int modifySelect = -1;
	printf("�˻��ϰ��� �ϴ� ������ �Է��ϼ���: ");
	BOOK titleKey;
	gets(titleKey.name);
	BOOK* titleP = (int*)bsearch(&titleKey, books, *nb, sizeof(BOOK), compareByName);
	if (titleP != NULL) {
		printBookInfo(titleP);
		printf("�ش� �ڷḦ �����Ͻðڽ��ϱ�?\n");
		printf("1. ����     2. ����     3. ������");
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
			// �迭�� �ε����� �����ͼ� i�� ����
			// i������ �迭���� memcpy(i, i+1)
			printf("===å ������ �����մϴ�.===\n");
			//memset(titleP, NULL, sizeof(BOOK));
			//(*nb)--;
			//(*pc)--;
			//int i, j = 0; //����
			//i = titleP - books; //���� �����ϰ��� �ϴ� �ε���
			//printf("%d", i); //����
			//for (int j = i; j < (*pc) -1; j++) { //����
			//	strcpy(books[i].name, books[i + 1].name);
			//	strcpy(books[i].author, books[i + 1].author);
			//	books[i].price = books[i + 1].price;
			//	memcpy(&books[i],&books[i+1], sizeof(BOOK)); //����

		//	for (int i = titleP - books; i < sizeof(books) / sizeof(BOOK) -2; i++) {
		//		//memcpy(&books[i], &books[i + 1], sizeof(BOOK));
		//			strcpy(books[i].name, books[i + 1].name);
		//		strcpy(books[i].author, books[i + 1].author);
		//		books[i].price = books[i + 1].price;
		//	}

			for (int i = 0; i < sizeof(books) / sizeof(BOOK); i++) {
				if (strcmp(titleP->name, books[i].name) == 0) {
					(*pc)--;
					printf("�����Ϸ�");

					if (i!= sizeof(books) / sizeof(BOOK) - 1) {
						for (int j = i; j < sizeof(books) / sizeof(BOOK); j++) {
							strcpy(books[i].name, books[i + 1].name);
							strcpy(books[i].author, books[i + 1].author);
							books[i].price = books[i + 1].price;
						}
						*books[sizeof(books) / sizeof(BOOK) - 1].name = NULL;
						*books[sizeof(books) / sizeof(BOOK) - 1].author = NULL;
					}
				}
			}
			(*pc)--;
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