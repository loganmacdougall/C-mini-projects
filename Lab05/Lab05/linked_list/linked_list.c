#include"linked_list.h"

LinkedList* llist_initialize(int itemSize, char* type) {
	LinkedList* llist = malloc(sizeof(LinkedList));

	llist->first = NULL;
	llist->last  = NULL;

	llist->size = 0;
	llist->itemSize = itemSize;
	llist->type = type;

	return llist;
}

bool  llist_add_at(LinkedList* llist, int index, void* element) {	
	if (index == 0) return llist_add_first(llist, element);
	if (llist == NULL) return false;
	if (index == llist->size - 1) return llist_add_last(llist, element);
	if (element == NULL) return false;
	if (index >= llist->size || index < 0) return false;
	
	Node* Next = llist->first;
	for (int i = 0; i < index; Next = Next->next);
	Node* Prev = Next->prev;

	void* cpy = malloc(llist->itemSize);
	memcpy(cpy, element, llist->itemSize);

	Node* newNode = malloc(sizeof(Node));
	newNode->data = cpy;
	newNode->next = Next;
	newNode->prev = Prev;

	Prev->next = newNode;
	Next->prev = newNode;

	llist->size++;
	return true;
}

bool  llist_add_first(LinkedList* llist, void* element) {
	if (llist == NULL) return false;
	if (element == NULL) return false;

	void* cpy = malloc(llist->itemSize);
	memcpy(cpy, element, llist->itemSize);

	Node* newFirst = malloc(sizeof(Node));
	newFirst->data = cpy;
	newFirst->prev = NULL;
	
	if (llist->size != 0) {
		llist->first->prev = newFirst;
		newFirst->next = llist->first;
	} else {
		newFirst->next = NULL;
		llist->last = newFirst;
	}
	llist->first = newFirst;

	llist->size++;
	return true;
}

bool  llist_add_last(LinkedList* llist, void* element) {
	if (llist == NULL) return false;
	if (element == NULL) return false;

	void* cpy = malloc(llist->itemSize);
	memcpy(cpy, element, llist->itemSize);

	Node* newLast = malloc(sizeof(Node));
	newLast->data = cpy;
	newLast->next = NULL;

	if (llist->size != 0) {
		llist->last->next = newLast;
		newLast->prev = llist->last;
	} else {
		newLast->prev = NULL;
		llist->first = newLast;
	}
	llist->last = newLast;

	llist->size++;
	return true;
}

void* llist_get(LinkedList* llist, int index) {
	if (llist == NULL) return NULL;
	if(index >= llist->size || index < 0) return NULL;

	Node* targetNode = llist->first;
	for (int i = 0; i < index; i++) targetNode = targetNode->next;

	return targetNode->data;
}

int   llist_index_of(LinkedList* llist, void* element) {
	if (llist == NULL) return -1;
	if (element == NULL) return -1;

	Node* targetNode = llist->first;
	for (int i = 0; targetNode != NULL; i++) {
		if (!memcmp(targetNode->data, element, llist->itemSize)) return i;
		targetNode = targetNode->next;
	}

	return -1;
}

void* llist_remove(LinkedList* llist, int index) {
	if (index == 0) return llist_remove_first(llist);
	if (llist == NULL) return NULL;
	if (index == llist->size - 1) return llist_remove_last(llist);
	if (llist->size == 0) return NULL;
	if (index >= llist->size || index < 0) return NULL;

	Node* deleteNode = llist->first;
	for (int i = 0; i < index; i++) deleteNode = deleteNode->next;

	void* element = malloc(llist->itemSize);
	memcpy(element, deleteNode->data, llist->itemSize);

	Node* Prev = deleteNode->prev;
	Node* Next = deleteNode->next;

	free(deleteNode->data);
	free(deleteNode);

	Prev->next = Next;
	Next->prev = Prev;

	llist->size--;
	return element;
}

void* llist_remove_first(LinkedList* llist) {
	if (llist == NULL) return NULL;
	if (llist->size == 0) return NULL;

	Node* First = llist->first;

	void* element = malloc(llist->itemSize);
	memcpy(element, First->data, llist->itemSize);

	Node* Next = First->next;

	free(First->data);	
	free(First);

	llist->first = Next;
	Next->prev = NULL;

	llist->size--;
	return element;	

}

void* llist_remove_last(LinkedList* llist) {
	if (llist == NULL) return NULL;
	if (llist->size == 0) return NULL;

	Node* Last = llist->last;

	void* element = malloc(llist->itemSize);
	memcpy(element, Last->data, llist->itemSize);

	Node* Prev = Last->prev;

	free(Last->data);	
	free(Last);

	llist->last = Prev;
	Prev->next = NULL;

	llist->size--;
	return element;	
	
}

bool  llist_destroy(LinkedList* llist) {
	if (llist == NULL) return false;
	Node* next = llist->first;
	while (next != NULL) {
		Node* tmp = next->next;
		free(next->data);
		free(next);
		next = tmp;
	}
	free(llist);

	return true;
}
