/* font.h */

#ifndef FONT_H
#define FONT_H

typedef struct font {
	char faceName[40];
	int size;
	int weight;
} FONT;

void PrintFont(const FONT* pFont);

#endif