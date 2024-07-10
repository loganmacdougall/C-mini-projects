#include"threads.h"

void* fill(void* args) {
    Args argsObj = *(Args*)args;
    int* arr = argsObj.arr;
    int start = argsObj.start;
    int end = argsObj.end;

    while(start < end) {
	arr[start] *= arr[start];
	start++;
    }

    return NULL;
}

void fill_memory(int* arr, int threadCount) {
    pthread_t threads[threadCount];
    Args args[threadCount];

    int N = 10000000;
    for(int i = 0; i < threadCount; i++) {
	args[i].arr = arr;
	args[i].start = (i*N)/(threadCount);
	args[i].end = ((i+1)*N)/(threadCount);

	pthread_create(&threads[i], NULL, fill, &args[i]);
    }

    for(int i = 0; i < threadCount; i++) {
	pthread_join(threads[i], NULL);
    }
}
