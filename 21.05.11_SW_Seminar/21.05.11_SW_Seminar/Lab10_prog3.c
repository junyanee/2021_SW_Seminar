#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct font {
	char faceName[40];  // ��Ʈ��
	unsigned int size;  // ��Ʈ ũ��
	int weight;         // ��Ʈ �β�
} FONT;

int CompareByName(const void* e1, const void* e2);

int main(void) {

	FONT fonts[3] = { {"�ü�", 10, 10}, {"����", 5, 5}, {"����", 3, 3} };
	qsort(fonts, 3, sizeof(FONT), CompareByName);
	// ����, �ü�, ���� ��

	char compareChar[40];

	printf("�˻��ϰ��� �ϴ� ��Ʈ���� �Է��ϼ���");
	gets(compareChar);
	printf("%d", strcmp(compareChar, bsearch(fonts->faceName, fonts, 3, sizeof(FONT), CompareByName)));



//	void bsearch(ã�� ���� �ּ�, ã�� ����� �Ǵ� �迭�ּ�, �迭�� ������Ʈ ����, �迭ũ��, ���Լ�);

	// void bsearch(, fonts, 3, sizeof(FONT), Compa);

	return 0;
}

int CompareByName(const void* e1, const void* e2) {
	const FONT* p1 = (const FONT*)e1;
	const FONT* p2 = (const FONT*)e2;
	return strcmp(p1->faceName, p2->faceName);
}