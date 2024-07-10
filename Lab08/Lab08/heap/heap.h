#ifndef __HEADER_HEAP
#define __HEADER_HEAP

#include"lib/array_list.h"
#include<stdbool.h>

typedef struct _Heap {
    ArrayList* list;
    int (*compare)(void*, void*);
    void (*print)(void*);
} Heap;

Heap* heap_initialize(int itemSize , char* type, int (*comparison)(void*, void*), void (*print)(void*));

bool  heap_insert(Heap* heap, void* element);
void* heap_remove(Heap* heap);
void* heap_peek(Heap* heap);
int   heap_size(Heap* heap);
bool  heap_contains(Heap* heap, void* element);
bool  _heapify(Heap* heap, int index);
bool  _heapify_up(Heap* heap, int index);
bool  _heap_swap_values(Heap* heap, int index1, int index2);
int   _heap_compare_indices(Heap* heap, int index1, int index2);

#endif
