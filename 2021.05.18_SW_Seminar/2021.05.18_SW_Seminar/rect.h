/* rect.h */

#ifndef RECT_H
#define RECT_H

typedef struct point {
	int x;
	int y;
} POINT;

typedef struct rect {
	POINT leftTop;
	POINT rightBottom;
} RECT;

int getHeight(const RECT *rect);
int getWidth(const RECT *rect);
void printRect(const RECT* rect);

#endif // !RECT_H
