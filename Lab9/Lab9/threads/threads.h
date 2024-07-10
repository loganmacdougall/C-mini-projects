#ifndef __HEADER_THREADS
#define __HEADER_THREADS

#include<pthread.h>
#include<stdbool.h>

typedef struct _Args {
    int* arr;
    int start;
    int end;
} Args;

void* fill(void* args);
void fill_memory(int* arr, int threadCount);

#endif
