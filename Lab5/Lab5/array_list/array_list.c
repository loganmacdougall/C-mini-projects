#include"array_list.h"

ArrayList* alist_initialize(int maxSize, int itemSize, char* type) {
	ArrayList* AList = malloc(sizeof(ArrayList));
	AList->size = 0;
	AList->maxSize = maxSize;
	AList->itemSize = itemSize;
	AList->type = type;

	AList->arr = malloc(sizeof(&AList->arr) * maxSize);

	return AList;
}

bool  alist_add(ArrayList* AList, void* element) {
	if (AList == NULL) return false;
	if (element == NULL) return false;
	if (AList->size == AList->maxSize) _alist_resize(AList);
	
	void* cpy = malloc(AList->itemSize);
	memcpy(cpy, element, AList->itemSize);

	AList->arr[AList->size] = cpy;
	AList->size++;
	return true;
}

bool  alist_add_at(ArrayList* AList, int index, void* element) {
	if (AList == NULL) return false;
	if (element == NULL) return false;
	if (index >= AList->size || index < 0) return false;
	if (AList->size == AList->maxSize) _alist_resize(AList);

	for (int i = AList->size; i != index; i--) {
		AList->arr[i] = AList->arr[i-1];
	}
	
	void* cpy = malloc(AList->itemSize);
	memcpy(cpy, element, AList->itemSize);

	AList->arr[index] = cpy;
	AList->size++;
	return true;
}

void  alist_clear(ArrayList* AList) {
	if (AList == NULL) return;
	for (int i = 0; i < AList->size; i++) {
		free(AList->arr[i]);
		AList->arr[i] = NULL;
	}
	AList->size = 0;
}

void* alist_get(ArrayList* AList, int index) {
	if (AList == NULL) return NULL;
	void* cpy = malloc(AList->itemSize);
	memcpy(cpy,AList->arr[index],AList->itemSize);

	return cpy;
}

int   alist_index_of(ArrayList* AList, void* element) {
	if (AList == NULL) return -1;
	for (int i = 0; i < AList->size; i++) {
		if (!memcmp(AList->arr[i], element, AList->itemSize)) {
			return i;
		}
	}

	return -1;
}

void* alist_remove(ArrayList* AList, int index) {
	if (AList == NULL) return NULL;
	if (index >= AList->size || index < 0) return NULL;

	void* element = alist_get(AList, index);

	free(AList->arr[index]);
	for (int i = index + 1; i < AList->size; i++) {
		AList->arr[i-1] = AList->arr[i];
	}

	AList->size--;
	return element;
}

bool  alist_destroy(ArrayList* AList) {
	if (AList == NULL) return false;
	for (int i = 0; i < AList->size; i++) {
		free(AList->arr[i]);
	}
	free(AList->arr);

	free(AList);
	AList = NULL;

	return true;
}

bool  _alist_resize(ArrayList* AList) {
	if (AList == NULL) return false;
	AList->maxSize *= 2;
	AList->arr = realloc(AList->arr, sizeof(&AList->arr) * AList->maxSize);
	
	return true;
}
