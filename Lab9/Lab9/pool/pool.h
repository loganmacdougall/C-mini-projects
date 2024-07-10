#ifndef __HEADER_POOL
#define __HEADER_POOL

#include<pthread.h>
#include<semaphore.h>
#include<stdbool.h>
#include<stdio.h>

#include"lib/queue.h"
#include"lib/array_list.h"
#include"lib/heap.h"

typedef struct _Operation {
    int (*op)(int, int);
    int a;
    int b;
} Operation;

typedef struct _Args {
    Operation* operation;
    bool is_complete;
} Args;

int add_op(int a, int b);
int sub_op(int a, int b);
int mul_op(int a, int b);

int compare(void* a, void* b);
void print(void* a);

void* compute(void* args);
bool read_operations(char* filename, Queue* operations);
ArrayList* execute_thread_pool(char* filename, int threadCount);
void print_sorted(ArrayList* integers);

#endif
