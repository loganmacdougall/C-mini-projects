#include"book.h"

Book* make_book(int maxLines) {
	Book* newBook = malloc(sizeof(Book));
	newBook->characterCount = 0;
	newBook->lineCount = 0;

	newBook->lines = malloc(maxLines * sizeof((*newBook->lines)));
}

void  burn_book(Book* book) {
	int numOfLines = book->lineCount;
	for (int i = 0; i < numOfLines; i++) {
		free(book->lines[i]);
	}
	free(book->lines);
	free(book);
	book = NULL;	
}

bool  save_book(Book* book, char* filename) {
	FILE* out = fopen(filename, "w");
	int numOfLines = book->lineCount;
	for (int i = 0; i < numOfLines; i++) {
		fputs(book->lines[i],out);
	}

	fclose(out);
	return true;	
}

bool  fill_book(Book* book, char* filename) {
	FILE* in = fopen(filename, "r");
	size_t bufferSize = 0;
	for (int i = 0;getline(&book->lines[i],&bufferSize,in) != EOF; i++) {
		book->lineCount++;
		book->characterCount+=strlen(book->lines[i]);
		bufferSize = 0;
	}

	fclose(in);
	return true;
}

int   edit_book(Book* book, char* word) {
	int numOfLines = book->lineCount;
	int removedLines = 0;
	char* line;

	for(int i = 0; i < numOfLines - removedLines; i++) {
		if (strstr(book->lines[i + removedLines], word) != NULL) {
			book->characterCount-=strlen(book->lines[i+removedLines]);
			free(book->lines[i + removedLines]);
			removedLines++;
			if ((i+removedLines) >= numOfLines) break;
			i--;
			continue;
		}

		book->lines[i] = book->lines[i + removedLines];
	}

	for(int i = numOfLines - removedLines; i < numOfLines; i++) {
		book->lines[i] = NULL;
	}

	book->lineCount = numOfLines - removedLines;
	return removedLines;
}

void  read_book(Book* book) {
	int numOfLines = book->lineCount;
	for(int i = 0; i < numOfLines; i++) {
		printf("%s", book->lines[i]);
	}
}
