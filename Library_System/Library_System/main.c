#include <stdio.h>

typedef struct book {
	char name[20];
	char author[30];
	int price;
}BOOK;

int main(void) {

	int select = 0;

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