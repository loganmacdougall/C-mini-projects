#include"safe.h"

sem_t sem;

void* counting(void* count) {
    Count* countObj = (Count*)count;
    while(true) {
	sem_wait(&sem);
	if (countObj->counter >= 1000) break;
        countObj->counter++;
	int value = countObj->counter;	
        printf("%d\n", value);
	sem_post(&sem);
    }
    sem_post(&sem);
}
void count_variable(int threadCount) {
    sem_init(&sem, 0, 1);
    
    Count count = {0};
    pthread_t threads[threadCount];

    for (int i = 0; i < threadCount; i++) {
        pthread_create(&threads[i], NULL, counting, &count);
    }

    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
    }
}
