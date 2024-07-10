#ifndef __HEADER_THREADS
#define __HEADER_THREADS

#include<pthread.h>
#include<semaphore.h>
#include<stdbool.h>
#include<stdio.h>

typedef struct _Count {
    int counter;
} Count;

void* counting(void* count);
void count_variable(int threadCount);

#endif
