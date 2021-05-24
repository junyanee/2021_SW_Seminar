#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "Menu.h"

// ���α׷��� ���۵� �� �ִ� ���� ������ ���� ������ ������ �Է� �޾Ƽ� ���� �޸𸮿� book ����ü �迭�� �Ѳ����� �Ҵ�


BOOK* reallocateBooks(BOOK* books, int* nb) {
	//rc = nb + 1;
	*nb = *nb + 1;
	if (books == NULL) {
		printf("���� �޸� �Ҵ� ����\n");
	}
	else {
		books = (BOOK*)realloc(books, sizeof(BOOK) * ((*nb) + 1));
	}
	return books;
}
int main(void) {

	int count = 0, numOfBook = 0;
	int* pc = &count;
	int* nb = &numOfBook;
	int reallocCount = 0;
	int* rc = &reallocCount;

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
				printf("�߰� ������ ���� [1��]�� �޸𸮸� �Ҵ��մϴ�.");
				printf("numofBook: %d,  count: %d", numOfBook, count);
				reallocateBooks(books, *nb);
				printf("numofBook: %d,  count: %d", numOfBook, count);

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
			qsort(books, numOfBook, sizeof(BOOK), compareByPrice);
			showBook(books, pc);
			break;



		case 0:
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
