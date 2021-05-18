/* Rect.c */

#include <stdio.h>
#include "rect.h"
#include <math.h>

int getHeight(const RECT *rect) {
	int height = abs(rect->leftTop.y - rect->rightBottom.y);
	printf("�簢���� ���̴� %d �Դϴ�\n", height);
	return height;
}

int getWidth(const RECT* rect) {
	int width = abs(rect->rightBottom.x - rect->leftTop.x);
	printf("�簢���� �ʺ�� %d �Դϴ�\n", width);
	return width;
}

void printRect(const RECT* rect) {
	printf("�簢���� �»������ %d,%d �̰� ���ϴ����� %d,%d �Դϴ�.\n���̴� %d�̰� �ʺ�� %d�Դϴ�\n", 
		rect->leftTop.x, rect->leftTop.y, rect->rightBottom.x, rect->rightBottom.y, 
		getHeight(rect), getWidth(rect));
}