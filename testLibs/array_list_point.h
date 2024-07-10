#ifndef __ARRAY_LIST_POINT_HEADER
#define __ARRAY_LIST_POINT_HEADER

#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct _AList {
        void** arr;
        int size;
        int maxSize;
        int itemSize;
        char* type;
} ArrayListPoint;

ArrayList* alist_initialize(int maxSize, int pointerSize, char* type);

bool  alist_add_p(ArrayList* AList, void* element);
bool  alist_add_at_p(ArrayList* AList, int index, void* element);
bool  alist_add_front_p(ArrayList* AList, void* element);
bool  alist_set_p(ArrayList* AList, int index, void* element);
void  alist_clear_p(ArrayList* AList);
void* alist_get_p(ArrayList* AList, int index);
int   alist_index_of_p(ArrayList* AList, void* element);
void* alist_remove_p(ArrayList* AList, int index);
void* alist_remove_front_p(ArrayList* AList);
void* alist_remove_end_p(ArrayList* AList);
void* alist_remove_pointer_p(ArrarrayList* AList);
bool  alist_destroy_p(ArrayList* AList);
bool  _alist_resize_p(ArrayList* AList);

#endif
