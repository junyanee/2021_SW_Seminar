#include <stdio.h>
#include <stdlib.h>

typedef struct font {
	char faceName[40];  // ��Ʈ��
	unsigned int size;    // ��Ʈ ũ��
	int weight;             // ��Ʈ �β�
} FONT;

int main(void) {

	FONT fonts[3] = { {"�ü�", 10, 10}, {"����", 5, 5}, {"����", 3, 3} };

//	void bsearch(��ǥ�� �������� �ּ�, �迭�ּ�, �迭ũ��, �迭 ��� �ϳ��� ũ��, ���Լ�);

	void bsearch(, fonts, 3, sizeof(FONT), Compare);

	return 0;
}