#include"array_list_point.h"

ArrayListPoint* alist_initialize(int maxSize, int pointerSize, char* type) {
        ArrayListPoint* AList = malloc(sizeof(ArrayList));
        AList->size = 0;
        AList->maxSize = maxSize;
        AList->itemSize = pointerSize;
        AList->type = type;

        AList->arr = malloc(sizeof(&AList->arr) * maxSize);

        return AList;
}

bool  alist_add(ArrayListPoint* AList, void* element) {
        if (AList == NULL) return false;
        if (element == NULL) return false;
        if (AList->size == AList->maxSize) _alist_resize(AList);

        AList->arr[AList->size] = element;
        AList->size++;
        return true;
}

bool  alist_add_at(ArrayListPoint* AList, int index, void* element) {
        if (AList == NULL) return false;
        if (element == NULL) return false;
        if (index >= AList->size || index < 0) return false;
        if (AList->size == AList->maxSize) _alist_resize(AList);

        for (int i = AList->size; i != index; i--) {
                AList->arr[i] = AList->arr[i-1];
        }

        AList->arr[index] = element;
        AList->size++;
        return true;
}

bool  alist_add_front(ArrayListPoint* AList, void* element) {
    if (AList == NULL) return false;
    if (AList->size == 0) return alist_add(AList, element);
    return alist_add_at(AList, 0, element);
}
bool  alist_set(ArrayListPoint* AList, int index, void* element) {
    if (AList == NULL) return false;
    if (element == NULL) return false;
    if (index >= AList->size || index < 0) return false;

    free(AList->arr[index]);

    AList->arr[index] = element;
    return true;

}
void  alist_clear(ArrayListPoint* AList) {
        if (AList == NULL) return;
        for (int i = 0; i < AList->size; i++) {
                AList->arr[i] = NULL;
        }
        AList->size = 0;
}

void* alist_get(ArrayListPoint* AList, int index) {
        if (AList == NULL) return NULL;
        return AList->arr[index];
}

int   alist_index_of(ArrayListPoint* AList, void* element) {
        if (AList == NULL) return -1;
        for (int i = 0; i < AList->size; i++) {
                if (!memcmp(AList->arr[i], element, AList->itemSize)) {
                        return i;
                }
        }

        return -1;
}

void* alist_remove(ArrayListPoint* AList, int index) {
        if (AList == NULL) return NULL;
        if (index >= AList->size || index < 0) return NULL;

        void* element = alist_get(AList, index);

        for (int i = index + 1; i < AList->size; i++) {
                AList->arr[i-1] = AList->arr[i];
        }

        AList->size--;
        return element;
}

void* alist_remove_front(ArrayListPoint* AList) {
    return alist_remove(AList, 0);
}
void* alist_remove_end(ArrayListPoint* AList) {
    return alist_remove(AList, AList->size - 1);
}

bool  alist_destroy(ArrayListPoint* AList) {
        if (AList == NULL) return false;
        
	free(AList->arr);
        free(AList);
        AList = NULL;

        return true;
}

bool  _alist_resize(ArrayListPoint* AList) {
        if (AList == NULL) return false;
        AList->maxSize *= 2;
        AList->arr = realloc(AList->arr, sizeof(&AList->arr) * AList->maxSize);

        return true;
}
