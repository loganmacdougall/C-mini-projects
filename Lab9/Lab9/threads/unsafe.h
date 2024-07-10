#ifndef __HEADER_UNSAFE
#define __HEADER_UNSAFE

#include<pthread.h>
#include<stdbool.h>
#include<stdio.h>

typedef struct _Count {
    int counter;
} Count;

void* counting(void* count);
void count_variable(int threadCount);

#endif
