#include"pool.h"

int add_op(int a, int b) {return a + b;}
int sub_op(int a, int b) {return a - b;}
int mul_op(int a, int b) {return a * b;}
    
int (*ops[3])(int, int) = {add_op, sub_op, mul_op};

int compare(void* a, void* b) {return *(int*)b - *(int*)a;}
void print(void* a) {printf("%d\n",*(int*)a);}

void* compute(void* args) {
    if (args == NULL) return NULL;
    Operation* op = ((Args*)args)->operation;
    int a = op->a;
    int b = op->b;
    
    int* result = malloc(sizeof(int));
    *result = op->op(a,b);

    ((Args*)args)->is_complete = true;
    return result;
}

bool read_operations(char* filename, Queue* operations) {
    if (filename == NULL || operations == NULL) return false;
    int op;
    int a;
    int b;

    FILE* in = fopen(filename, "r");
    while(fscanf(in, "%d %d %d",&op, &a, &b) != EOF) {
            Operation* operation =  malloc(sizeof(Operation));
            
	    operation->op = ops[op];
            operation->a = a;
            operation->b = b;

	    queue_enqueue(operations, operation);

	    free(operation);
    }
  
    fclose(in);
    return true;    
}

ArrayList* execute_thread_pool(char* filename, int threadCount) { 
    Queue* operations = queue_initialize(sizeof(Operation), "Operation");
    read_operations(filename, operations);

    int len = queue_size(operations);

    ArrayList* list = alist_initialize(len,sizeof(int),"int"); 
    Args args[threadCount];
    pthread_t threads[threadCount];
    
    for(int i = 0; i < threadCount; i++) {
	Operation* op = queue_dequeue(operations);
	args[i].operation = op;
	args[i].is_complete = false;
	pthread_create(&threads[i], NULL, compute, &args[i]);
    }

    int* result = NULL;

    for (int i = 0;queue_size(operations);i = (i+1) % threadCount) {
	if (args[i].is_complete == true) {
	    pthread_join(threads[i], (void**) &result);
	    alist_add(list, result);
	    free(result);
	    free(args[i].operation);
	    Operation* op = queue_dequeue(operations);
	    args[i].operation = op;
	    args[i].is_complete = false;
	    pthread_create(&threads[i], NULL, compute, &args[i]);
	}
    }

    for (int i = 0;i < threadCount; i++) {
	pthread_join(threads[i], (void**) &result);
	alist_add(list, result);
	free(result);
	free(args[i].operation);
    }

    queue_destroy(operations);
    return list;
}
void print_sorted(ArrayList* integers) {
    Heap* heap = heap_initialize(sizeof(int), "int", compare, print);
    for (int i = 0;i <  integers->size; i++) {
	void* data = alist_get(integers, i);
	heap_insert(heap, data);
	free(data);
    }
    while(heap_size(heap)) {
	void* data = heap_remove(heap);
	heap->print(data);
	free(data);
    }
    heap_destroy(heap);
}
