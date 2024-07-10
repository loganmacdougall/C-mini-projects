#ifndef __STACK_HEADER
#define __STACK_HEADER

#include"lib/array_list.h"
#include<stdbool.h>

typedef struct _Stack {
    ArrayList* list;
} Stack;

Stack* stack_initialize(int itemSize, char* type);

bool  stack_push(Stack* stack, void* element);
void* stack_pop(Stack* stack);
void* stack_peek(Stack* stack);
int   stack_size(Stack* stack);
bool  stack_contains(Stack* stack, void* element);
bool  stack_destroy(Stack* stack);

#endif
