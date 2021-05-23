#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Menu.h"
#include "Book.h"


int printMenu() {
	int select = -1;
	printf(" ================================================\n");
	printf(" |  ���� ���� ���α׷�                          |\n");
	printf(" |  1. ���� �Է�                                |\n");
	printf(" |  2. ���� �˻�                                |\n");
	printf(" |  3. ���� �˻�                                |\n");
	printf(" |  4. ���� ������ ����	                        |\n");
	printf(" |  5. ��ü ���� ���� ���                      |\n");
	printf(" |  6. ����                                     |\n");
	printf(" |                      authored by JunHyunPark |\n");
	printf(" ================================================\n");
	printf("\n");
	printf("�޴��� �����ϼ��� : \n");
	scanf("%d", &select);
	getchar();
	return select;
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