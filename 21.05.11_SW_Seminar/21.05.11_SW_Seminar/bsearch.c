#include <stdio.h>
#include <stdlib.h>

typedef struct font {
	char faceName[40];  // 폰트명
	unsigned int size;    // 폰트 크기
	int weight;             // 폰트 두께
} FONT;

int main(void) {

	FONT fonts[3] = { {"궁서", 10, 10}, {"돋음", 5, 5}, {"굴림", 3, 3} };

//	void bsearch(목표값 데이터의 주소, 배열주소, 배열크기, 배열 요소 하나당 크기, 비교함수);

	void bsearch(, fonts, 3, sizeof(FONT), Compare);

	return 0;
}