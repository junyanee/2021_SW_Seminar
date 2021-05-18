/* Main.c */

#include <stdio.h>
#include "rect.h"

int main(void) {

	RECT rect = { 20, 20, 10, 10 };
	printRect(&rect);

	return 0;
}