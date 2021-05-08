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
		printf("���� ���� ���α׷�\n");
		printf("1. ���� �Է�\n");
		printf("2. ���ں� �˻�\n");
		printf("3. ���� �˻�\n");
		printf("4. ���� ������ ����\n");
		printf("5. ����\n");
		printf("\n");
		printf("�޴��� �����ϼ��� : \n");
		scanf("%d", &select);

		switch (select)
		{
		case 1 :
			printf("���� �Է��� �����ϼ̽��ϴ�.\n");
			addBook(p);
			showBook(p);
			break;

		case 2 :
			printf("���ں� �˻��� �����ϼ̽��ϴ�.\n");

			break;
		case 3 :
			printf("���� �˻��� �����ϼ̽��ϴ�.\n");

			break;
		case 4 :
			printf("���� ������ ������ �����ϼ̽��ϴ�.\n");

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
	printf("*** ���ο� ������ �߰��մϴ� ***\n");

	printf("������ �Է��ϼ���: \n");
	scanf("%s", book->name);
	printf("���ڸ� �Է��ϼ���: \n");
	scanf("%s", book->author);
	printf("������ �Է��ϼ���: \n");
	scanf("%d", book->price);

}
void showBook(BOOK* book) {
	for (int i = 0; i < 10; i++) {
		printf("����: %s\n", book->name);
		printf("����: %s\n", book->author);
		printf("����: %d ��\n", book->price);
	}
}