#ifndef __BOOK_HEADER
#define __BOOK_HEADER
#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct _Book {
	int characterCount;
	int lineCount;
	char** lines;
} Book;

Book* make_book(int maxLines);
void  burn_book(Book* book);
bool  save_book(Book* book, char* filename);
bool  fill_book(Book* book, char* filename);
int   edit_book(Book* book, char* word);
void  read_book(Book* book);

#endif
