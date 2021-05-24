/* Book.h */

#ifndef BOOK_H
#define BOOK_H

typedef struct book {
	char name[40];
	char author[30];
	int price;
} BOOK;

BOOK* allocateBooks(int * nb);
BOOK* reallocateBooks(BOOK* books, int* nb);
int freeMemory(BOOK* books);
void addBook(BOOK* books, int* pc);
void showBook(BOOK* books, int* pc);
void findBookByAuthor(BOOK* books, int* pc, int* nb);
void findBookByTitle(BOOK* books, int* pc, int* nb);
void printBookInfo(const BOOK* p);

#endif