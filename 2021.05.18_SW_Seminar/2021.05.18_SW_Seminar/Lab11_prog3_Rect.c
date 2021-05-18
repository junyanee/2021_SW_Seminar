/* Rect.c */

#include <stdio.h>
#include "rect.h"
#include <math.h>

int getHeight(const RECT *rect) {
	int height = abs(rect->leftTop.y - rect->rightBottom.y);
	printf("사각형의 높이는 %d 입니다\n", height);
	return height;
}

int getWidth(const RECT* rect) {
	int width = abs(rect->rightBottom.x - rect->leftTop.x);
	printf("사각형의 너비는 %d 입니다\n", width);
	return width;
}

void printRect(const RECT* rect) {
	printf("사각형의 좌상단점은 %d,%d 이고 우하단점은 %d,%d 입니다.\n높이는 %d이고 너비는 %d입니다\n", 
		rect->leftTop.x, rect->leftTop.y, rect->rightBottom.x, rect->rightBottom.y, 
		getHeight(rect), getWidth(rect));
}