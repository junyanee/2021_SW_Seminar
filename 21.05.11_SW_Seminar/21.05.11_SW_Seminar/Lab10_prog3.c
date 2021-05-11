#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct font {
	char faceName[40];  // ��Ʈ��
	unsigned int size;  // ��Ʈ ũ��
	int weight;         // ��Ʈ �β�
} FONT;

int CompareByName(const void* e1, const void* e2);
int Compare(const void *cmp1, const void* cmp2);
void printFontInfo(const FONT* p);

int main(void) {

	FONT fonts[3] = { {"�ü�", 10, 10}, {"����", 5, 5}, {"����", 3, 3} };
	qsort(fonts, 3, sizeof(FONT), CompareByName);
	// ����, �ü�, ���� ��

	char userInput[40];
	FONT* fontP;

	int select = -1;
	while (1) {
		printf("�޴��� �����ϼ���\n");
		printf("0. ����\n");
		printf("1. ��Ʈ �˻�\n");
		scanf("%d", &select);
		getchar(); //���Ͱ� ����

		switch (select)
		{
		case 0:
			return 0;
			break;

		case 1:
			printf("��Ʈ �˻�\n");
			printf("�˻��ϰ��� �ϴ� ��Ʈ���� �Է��ϼ���\n");
			gets(userInput);
			//	void bsearch(ã�� ���� �ּ�, ã�� ����� �Ǵ� �迭�ּ�, �迭�� ������Ʈ ����, �迭ũ��, ���Լ�);
			fontP = (FONT *) bsearch(userInput, fonts, 3, sizeof(FONT), CompareByName);
			printf("\n");
			printFontInfo(fontP);
			break;

		default:
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
	}
	return 0;
}

int CompareByName(const void* e1, const void* e2) {
	const FONT* p1 = (const FONT*)e1;
	const FONT* p2 = (const FONT*)e2;
	return strcmp(p1->faceName, p2->faceName);
}
int Compare(const void* cmp1, const void* cmp2) {
	return strcmp((char* ) cmp1, (char* ) cmp2);
}
void printFontInfo(const FONT* p) {
	printf("��Ʈ��: %s\n", p->faceName);
	printf("��Ʈũ��: %d\n", p->size);
	printf("��Ʈ�β�: %d\n", p->weight);
	printf("\n");
}