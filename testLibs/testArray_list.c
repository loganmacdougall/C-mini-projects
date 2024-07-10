#include"array_list.h"
#include<stdio.h>

int main() {
    printf("Creating an arraylist: ");
    ArrayList* list = alist_initialize(10, sizeof(int), "int");
    printf("SUCCESS\n");

    printf("Placing 8 items into the arraylist:\n");
    int numbers[] = {4,6,3,23,9,1,90,-5};
    int insertOrder[] = {-5, 4, 90, 1, 6, 3, 23, 9};
    int removeOrder[] = {-5, 9, 4, 23, 90, 3, 1, 6};
    for (int i = 0; i < 5; i++) alist_add(list, &numbers[i]);
    alist_add_at(list, 1, &numbers[5]);
    alist_add_at(list, 1, &numbers[6]);
    alist_add_front(list, &numbers[7]);
    for(int i = 0; i < 8; i++) {
	int* listValue = alist_get(list, i);
	printf("exp: %d, act: %d\n",insertOrder[i], *listValue);
	if (insertOrder[i] != *listValue) {
	    printf("FAIL\n");
	    return 0;
	}
	free(listValue);
    }
    printf("SUCCESS\n");

    ArrayListPoint* pointerList = alist_initialize_p(10, sizeof(int*), "int");

    for (int i = 0; i < 8; i++) {
	
    }

    alist_destroy(list);

    /*
    printf("Removing all items from the arraylist: \n");
    for (int i = 0; i < 8; i++) {
	int* listValue;
	if (i % 2 == 0) listValue = alist_remove_front(list);
	else listValue = alist_remove_end(list);
	printf("exp: %d, act: %d\n",removeOrder[i], *listValue);
	if (removeOrder[i] != *listValue) {
	    printf("FAIL\n");
	    return 0;
	}	
    }
    printf("SUCCESS\n");
    */

    return 0;
}
