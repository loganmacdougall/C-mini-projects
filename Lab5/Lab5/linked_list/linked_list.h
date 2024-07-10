#ifndef __HEADER_LINKED_LIST
#define __HEADER_LINKED_LIST

#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node {
	void* data;
	struct _Node* next;
	struct _Node* prev;
} Node;

typedef struct _LinkedList {
	Node* first;
	Node* last;
	int size;
	int itemSize;
	char* type;
} LinkedList;

LinkedList* llist_initialize(int itemSize, char* type);

void  print(LinkedList* llist);
bool  llist_add_at(LinkedList* llist, int index, void* element);
bool  llist_add_first(LinkedList* llist, void* element);
bool  llist_add_last(LinkedList* llist, void* element);
void* llist_get(LinkedList* llist, int index);
int   llist_index_of(LinkedList* llist, void* element);
void* llist_remove(LinkedList* llist, int index);
void* llist_remove_first(LinkedList* llist);
void* llist_remove_last(LinkedList* llist);
bool  llist_destroy(LinkedList* llist);

#endif
