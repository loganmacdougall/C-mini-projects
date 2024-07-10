#ifndef __QUEUE_HEADER
#define __QUEUE_HEADER

#include"lib/array_list.h"
#include<stdbool.h>

typedef struct _Queue {
    ArrayList* list;
} Queue;

Queue* queue_initialize(int itemSize, char* type);

bool  queue_enqueue(Queue* queue, void* element);
void* queue_dequeue(Queue* queue);
void* queue_peek(Queue* queue);
int   queue_size(Queue* queue);
bool  queue_contains(Queue* queue, void* element);
bool  queue_destroy(Queue* queue);

#endif
