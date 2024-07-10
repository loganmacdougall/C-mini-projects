#ifndef __ARRAY_LIST_HEADER
#define __ARRAY_LIST_HEADER

#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct _AList {
	void** arr;
	int size;
	int maxSize;
	int itemSize;
	char* type;
} ArrayList;

ArrayList* alist_initialize(int maxSize, int itemSize, char* type);

bool  alist_add(ArrayList* AList, void* element);
bool  alist_add_at(ArrayList* AList, int index, void* element);
bool  alist_add_front(ArrayList* AList, void* element);
bool  alist_set(ArrayList* AList, int index, void* element);
void  alist_clear(ArrayList* AList);
void* alist_get(ArrayList* AList, int index);
int   alist_index_of(ArrayList* AList, void* element);
void* alist_remove(ArrayList* AList, int index);
void* alist_remove_front(ArrayList* AList);
void* alist_remove_end(ArrayList* AList);
bool  alist_destroy(ArrayList* AList);
bool  _alist_resize(ArrayList* AList);

#endif
