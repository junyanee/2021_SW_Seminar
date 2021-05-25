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
			printf("���� �Է��� �����ϼ̽��ϴ�.\n");
			printf("numofbook: %d, count: %d", numOfBook, count);
			printf("[%d��]���� �߰� ������ �� �ֽ��ϴ�.\n", numOfBook - count);
			if (count == numOfBook) {
				printf("=== ������ �� �ִ� ������ �� á���ϴ�.=== \n");
				printf("�߰� ������ ���� [5��]�� �޸𸮸� �Ҵ��մϴ�.\n");
				numOfBook += 5;
				books = reallocateBooks(books, nb);
				addBook(books, pc);
			}
			else {
				addBook(books, pc);
			}
			break;

		case 2:
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByAuthor);
			findBookByAuthor(books, pc, nb);
			break;

		case 3:
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByName);
			findBookByTitle(books, pc, nb);
			break;

		case 4:
			printf("���� ������ ������ �����ϼ̽��ϴ�.\n");
			qsort(books, numOfBook, sizeof(BOOK), compareByPrice);
			showBook(books, pc);
			break;

		case 5:
			//qsort(books, numOfBook, sizeof(BOOK), compareByPrice);
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
