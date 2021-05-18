/* font.c */

#include <stdio.h>
#include "font.h"
#include "font.h"

int main(void) {

	FONT font1 = { "±¼¸²", 10, 2 };
	PrintFont(&font1);

	return 0;
}

void PrintFont(const FONT* pFont) {
	printf("%s", pFont->faceName);
	printf("%d", pFont->size);
	printf("%d", pFont->weight);
}
