#include"unsafe.h"

void* counting(void* count) {
    while(((Count*)count)->counter < 1000) {
	((Count*)count)->counter++;
	printf("%d\n", ((Count*)count)->counter);
    }
}

void count_variable(int threadCount) {
    Count count = {0};
    pthread_t threads[threadCount];

    for (int i = 0; i < threadCount; i++) {
	pthread_create(&threads[i], NULL, counting, &count);
    }

    for (int i = 0; i < threadCount; i++) {
	pthread_join(threads[i], NULL);
    }
}
