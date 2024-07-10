#ifndef __HEADER_DICTIONARY
#define __HEADER_DICTIONARY

#include"lib/bintree.h"
#include"lib/array_list.h"
#include<stdbool.h>

typedef struct _Pair {
    void* first;
    void* second;
} Pair;

typedef struct _Dictionary {
    BinaryTree* tree;
} Dictionary;

Dictionary* dict_initialize(int (*compare)(void*, void*), void (*print)(void*));

bool dict_insert(Dictionary* dict, void* key, void* value);
void* dict_get(Dictionary* dict, void* key);
ArrayList* dict_key_list(Dictionary* dict, int keySize);
bool dict_contains(Dictionary* dict, void* key);
void* _dict_get_recursive(BinaryTree* tree, Pair* key, BinaryTreeNode* node);
void _dict_key_list_recursive(BinaryTree* tree, ArrayList* list, BinaryTreeNode* node);

#endif
