#ifndef __HEADER_BINTREE
#define __HEADER_BINTREE

#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"lib/queue.h"

typedef struct _BinTreeNode {
    void* data;
    struct _BinTreeNode* left;
    struct _BinTreeNode* right;
} BinaryTreeNode;

typedef struct _BinaryTree {
    BinaryTreeNode* top;
    int itemSize;
    char* type;

    int (*compare)(void*, void*);
    void (*print)(void*);
} BinaryTree;

BinaryTree* bintree_initialize(int itemSize, char* type, int (*compare)(void*, void*), void (*print)(void*));
BinaryTreeNode* bintree_create_node(int dataSize, void* data);

bool bintree_set_node(BinaryTreeNode* node, int dataSize, void* data);

bool bintree_insert(BinaryTree* binTree, void* element);
bool bintree_search(BinaryTree* binTree, void* element);
void bintree_print_in_order(BinaryTree* binTree);
void bintree_print_pre_order(BinaryTree* binTree);
void bintree_print_post_order(BinaryTree* binTree);
void bintree_print_reverse_order(BinaryTree* binTree);
void bintree_print_breadth_first(BinaryTree* binTree);
void bintree_print_depth_first(BinaryTree* binTree);
bool bintree_insert_replace(BinaryTree* binTree, void* element);
bool bintree_destroy(BinaryTree* binTree);
bool _bintree_insert_recursive(BinaryTree* binTree, BinaryTreeNode* node, void* element);
bool _bintree_search_recursive(BinaryTree* binTree, BinaryTreeNode* node, void* element);
void _bintree_in_order_recursive(BinaryTree* binTree, BinaryTreeNode* node);
void _bintree_pre_order_recursive(BinaryTree* binTree, BinaryTreeNode* node);
void _bintree_post_order_recursive(BinaryTree* binTree, BinaryTreeNode* node);
void _bintree_reverse_order_recursive(BinaryTree* binTree, BinaryTreeNode* node);
bool _bintree_insert_replace_recursive(BinaryTree* binTree, BinaryTreeNode* node, void* element);
void _bintree_destroy_recursive(BinaryTree* binTree, BinaryTreeNode* node);

#endif
