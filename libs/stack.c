#include"stack.h"

Stack* stack_initialize(int itemSize, char* type) {
    Stack* stack = malloc(sizeof(Stack));

    stack->list = alist_initialize(10, itemSize, type);
    return stack;
}

bool stack_push(Stack* stack, void* element) {
    if (stack == NULL) return false;
    return alist_add(stack->list, element);
}
void* stack_pop(Stack* stack) {
    if (stack == NULL) return NULL;
    return alist_remove_end(stack->list);
}
void* stack_peek(Stack* stack) {
    if (stack == NULL) return NULL;
    if (stack->list->size <= 0) return NULL;
    return alist_get(stack->list, stack->list->size - 1);
}
int stack_size(Stack* stack) {
    if (stack == NULL) return -1;
    return stack->list->size;
}
bool stack_contains(Stack* stack, void* element) {
    if (stack == NULL) return false;
    return alist_index_of(stack->list, element) == -1 ? false : true;
}
bool stack_destroy(Stack* stack) {
    if (stack == NULL) return false;
    alist_destroy(stack->list);
    free(stack);

    return true;
}

