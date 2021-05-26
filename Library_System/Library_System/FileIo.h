/* FileIo.h */

#ifndef FILEIO_H
#define FILEIO_H

void loadBookListInfo(int* nb, int* pc);
void loadBookList(BOOK* books, int* nb, int* pc);
void saveBookList(BOOK* books, int numberOfBook, int count);

#endif