#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "Menu.h"

// ���α׷��� ���۵� �� �ִ� ���� ������ ���� ������ ������ �Է� �޾Ƽ� ���� �޸𸮿� book ����ü �迭�� �Ѳ����� �Ҵ�

int main(void) {

	int count = 0, numOfBook = 0;
	int* pc = &count;
	int* nb = &numOfBook;

	BOOK* books = NULL;

	printf("����� å�� �Ǽ��� �Է��ϼ���: \n");
	scanf("%d", &numOfBook);
	while (getchar() != '\n');

	books = allocateBooks(nb);

	if (books == NULL) {
		return -1;
	}

	while (1) {

		switch (printMenu())
		{
		case 1:
			printf("���� �Է��� �����ϼ̽��ϴ�.");
			printf("[%d��]���� �߰� ������ �� �ֽ��ϴ�.\n", numOfBook - count);
			if (count == numOfBook) {
				printf("������ �� �ִ� ������ �� á���ϴ�.\n");
			}
			else {
				addBook(books, pc);
			}
			break;

		case 2:
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByAuthor);
			findBookByAuthor(books);
			break;

		case 3:
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByName);
			findBookByTitle(books);
			break;

		case 4:
			printf("���� ������ ������ �����ϼ̽��ϴ�.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByPrice);
			showBook(books, pc);
			break;

		case 5:
			showBook(books, pc);
			break;

		case 6:
			printf("�����մϴ�.\n");
			freeMemory(books);
			return 0;
			break;

		default:
			printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
	}

	return 0;
}
