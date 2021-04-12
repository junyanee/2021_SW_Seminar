#include <stdio.h>

typedef enum week {sun = 0, mon, tue, wed, thu, fri, sat, weekMaxCount} dayOfWeek;

int main(void) {

	for (dayOfWeek i = sun; i < weekMaxCount; i++) {
		printf("%d\n", i);
	}

	return 0;
}