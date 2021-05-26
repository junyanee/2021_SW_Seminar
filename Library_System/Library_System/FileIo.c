#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "Menu.h"
#include "FileIo.h"

void loadBookListInfo(int* nb , int* pc) {
	FILE* fp;
	fp = fopen("book.txt", "r");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}
	fscanf(fp, "%d\n", nb);
	fscanf(fp, "%d\n", pc);

	fclose(fp);
}

void loadBookList(BOOK* books, int* nb, int* pc) {
	FILE* fp;
	fp = fopen("book.txt", "r");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}
	fscanf(fp, "%d\n", nb);
	fscanf(fp, "%d\n", pc);
	for (int i = 0; i <  *pc; i++) {
		fscanf(fp, "%s %s %d\n", books[i].name, books[i].author, &books[i].price);
	}

	fclose(fp);
}

void saveBookList(BOOK* books, int numberOfBook, int count) {
	FILE* fp;
	fp = fopen("book.txt", "w");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}
	fprintf(fp, "%d\n", numberOfBook);
	fprintf(fp, "%d\n", count);

	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %s %d\n", books[i].name, books[i].author, books[i].price);
	}

	fclose(fp);
}