/* Book.h */

#ifndef BOOK_H
#define BOOK_H

typedef struct book {
	char name[40];
	char author[30];
	int price;
} BOOK;

BOOK* allocateBooks(int * nb);
int freeMemory(BOOK* books);
void addBook(BOOK* books, int* pc);
void showBook(BOOK* books, int* pc);
void findBookByAuthor(BOOK* books);
void findBookByTitle(BOOK* books);
void printBookInfo(const BOOK* p);

#endif