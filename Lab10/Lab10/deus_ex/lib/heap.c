#include"heap.h"

Heap* heap_initialize(int itemSize , char* type, int (*compare)(void*, void*), void (*print)(void*)) {
   Heap* heap = malloc(sizeof(Heap));
   heap->list = alist_initialize(10, itemSize, type);
   heap->compare = compare;
   heap->print = print;

   return heap;
}

bool  heap_insert(Heap* heap, void* element) {
    if (heap == NULL) return false;
    if (element == NULL) return false;
    alist_add(heap->list, element);
    _heapify_up(heap, heap->list->size - 1);
    return true;
}
void* heap_remove(Heap* heap) {
    if (heap == NULL) return NULL;
    _heap_swap_values(heap, 0, heap->list->size - 1);
    void* element =  alist_remove_end(heap->list);
    _heapify(heap, 0);
    return element;

}
void* heap_peek(Heap* heap) {
    if (heap == NULL) return NULL;
    return alist_get(heap->list, 0);
}
int   heap_size(Heap* heap) {
    return heap->list->size;
}
bool  heap_contains(Heap* heap, void* element) {
    for (int i = 0; i < heap->list->size; i++) {
	void* tmp = alist_get(heap->list, i);
	if (!heap->compare(element, tmp)) return true;
	free(tmp);
    }
    return false;
}

bool  _heapify(Heap* heap, int index) {
    if (heap == NULL) return false;
    if (index < 0 || index >= heap->list->size) return false;
    if (index == heap->list->size - 1) return true;

    int leftChildIndex  = (2*index) + 1;
    int rightChildIndex = (2*index) + 2;

    int top = index;

    if (leftChildIndex < heap->list->size) {
	int compare = _heap_compare_indices(heap, top, leftChildIndex);
	if (compare < 0) top = leftChildIndex;
	
	if (rightChildIndex < heap->list->size) {
	    compare = _heap_compare_indices(heap, top, rightChildIndex);
	    if (compare < 0) top = rightChildIndex;
	}
    }
    if (top != index) {
	_heap_swap_values(heap, index, top);
	return _heapify(heap, top);
    }
    return true;
}
bool  _heapify_up(Heap* heap, int index) {
    if (heap == NULL) return false;
    if (index < 0 || index >= heap->list->size) return false;
    if (index == 0) return true;

    int parentIndex = (index - 1)/2;
    
    int compare = _heap_compare_indices(heap, index, parentIndex);
    if (compare > 0) {
	_heap_swap_values(heap, index, parentIndex);
	_heapify_up(heap, parentIndex);
    }
}
bool  _heap_swap_values(Heap* heap, int index1, int index2) {
    if (heap == NULL) return false;
    if (index1 < 0 || index1 >= heap->list->size) return false;
    if (index2 < 0 || index2 >= heap->list->size) return false;
    if (index1 == index2) return false;

    void* element1 = alist_get(heap->list, index1);
    void* element2 = alist_get(heap->list, index2);
   
    alist_set(heap->list, index1, element2);
    alist_set(heap->list, index2, element1);

    free(element1);
    free(element2);

    return true;
}
int _heap_compare_indices(Heap* heap, int index1, int index2) {
    if (index1 == index2) return 0;

    void* element1 = alist_get(heap->list, index1);
    void* element2 = alist_get(heap->list, index2);

    int result = heap->compare(element1, element2);

    free(element1);
    free(element2);

    return result;
}
bool heap_destroy(Heap* heap) {
   if (heap == NULL) return true;
   alist_destroy(heap->list);
   free(heap);
   heap = NULL;

   return true;
}
