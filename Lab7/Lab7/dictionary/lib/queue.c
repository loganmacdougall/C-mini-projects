#include"queue.h"

Queue* queue_initialize(int itemSize, char* type) {
    Queue* queue = malloc(sizeof(queue));

    queue->list = alist_initialize(10, itemSize, type);
    return queue;
}

bool queue_enqueue(Queue* queue, void* element) {
    if (queue == NULL) return false;
    return alist_add_front(queue->list, element);
}
void* queue_dequeue(Queue* queue) {
    if (queue == NULL) return NULL;
    return alist_remove_end(queue->list);
}
void* queue_peek(Queue* queue) {
    if (queue == NULL) return NULL;
    if (queue->list->size <= 0) return NULL;
    return alist_get(queue->list, queue->list->size - 1);
}
int queue_size(Queue* queue) {
    if (queue == NULL) return -1;
    return queue->list->size;
}
bool queue_contains(Queue* queue, void* element) {
    if (queue == NULL) return false;
    return alist_index_of(queue->list, element) == -1 ? false : true;
}
bool queue_destroy(Queue* queue) {
    if (queue == NULL) return false;
    alist_destroy(queue->list);
    free(queue);

    return true;
}
