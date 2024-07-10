#include"bintree.h"

BinaryTree* bintree_initialize(int itemSize, char* type, int (*compare)(void*, void*), void (*print)(void*)) {
    BinaryTree* binTree = malloc(sizeof(BinaryTree));
    binTree->top = NULL;
    binTree->itemSize = itemSize;
    binTree->type = type;
    binTree->compare = compare;
    binTree->print = print;

    return binTree;

}
BinaryTreeNode* bintree_create_node(int dataSize, void* data) {
    if (data == NULL) return NULL;
    BinaryTreeNode* node = malloc(sizeof(BinaryTreeNode));
    node->data = malloc(dataSize);
    memcpy(node->data, data, dataSize);

    return node;
}

bool bintree_set_node(BinaryTreeNode* node, int dataSize, void* data) {
    if (node == NULL) return false;
    if (node->data != NULL) {
	free(node->data);
    }
    
    node->data = malloc(dataSize);
    memcpy(node->data, data, dataSize);
    return true;
}

bool bintree_insert(BinaryTree* binTree, void* element) {
    if (binTree == NULL) return false;
    if (element == NULL) return false;
    if (binTree->top == NULL) {
	binTree->top = bintree_create_node(binTree->itemSize, element);
	return true;
    }

    return _bintree_insert_recursive(binTree, binTree->top, element);
}
bool bintree_search(BinaryTree* binTree, void* element) {
    if (binTree == NULL) return false;
    if (element == NULL) return false;
    return _bintree_search_recursive(binTree, binTree->top, element);
}
void bintree_print_in_order(BinaryTree* binTree) {
    if (binTree == NULL) return;
    _bintree_in_order_recursive(binTree, binTree->top);
}
void bintree_print_pre_order(BinaryTree* binTree) {
    if (binTree == NULL) return;
    _bintree_pre_order_recursive(binTree, binTree->top);
}
void bintree_print_post_order(BinaryTree* binTree) {
    if (binTree == NULL) return;
    _bintree_post_order_recursive(binTree, binTree->top);
}
void bintree_print_reverse_order(BinaryTree* binTree) {
    if (binTree == NULL) return;
    _bintree_reverse_order_recursive(binTree, binTree->top); 
}
void bintree_print_breadth_first(BinaryTree* binTree) {
    if (binTree == NULL) return;
    Queue* toBePrinted = queue_initialize(sizeof(BinaryTreeNode), "BinaryTreeNode");
    queue_enqueue(toBePrinted, binTree->top);
    BinaryTreeNode* tmpNode;
    while(queue_size(toBePrinted) > 0) {
	tmpNode = queue_dequeue(toBePrinted);
	queue_enqueue(toBePrinted, tmpNode->left);
	queue_enqueue(toBePrinted, tmpNode->right);
	binTree->print(tmpNode->data);
    }
}
void bintree_print_depth_first(BinaryTree* binTree) {
    bintree_print_pre_order(binTree);
}
bool bintree_insert_replace(BinaryTree* binTree, void* element) {
    if (binTree == NULL) return false;
    if (element == NULL) return false;
    if (binTree->top == NULL) {
	binTree->top = bintree_create_node(binTree->itemSize, element);
	return true;
    }

    return _bintree_insert_replace_recursive(binTree, binTree->top, element);
}
bool bintree_destroy(BinaryTree* binTree) {
    if (binTree == NULL) return false;
    _bintree_destroy_recursive(binTree, binTree->top);
    free(binTree);
    binTree = NULL;

    return true;
}

bool _bintree_insert_recursive(BinaryTree* binTree, BinaryTreeNode* node, void* element) {
    int compare = binTree->compare(node->data, element);
    if (compare < 0) {
	if (node->left == NULL) {
	    node->left = bintree_create_node(binTree->itemSize, element);
	    return true;
	} else {
	    return _bintree_insert_recursive(binTree,node->left, element);
	}
    } else {
	if (node->right == NULL) {
	    node->right = bintree_create_node(binTree->itemSize, element);
	    return true;
	} else {
	    return _bintree_insert_recursive(binTree,node->right, element);
	}
    }
}
bool _bintree_search_recursive(BinaryTree* binTree, BinaryTreeNode* node, void* element) {
    if (node == NULL) return false;
    int compare = binTree->compare(node->data, element);

    if (compare < 0) {
	return _bintree_search_recursive(binTree, node->left, element);
    } else if (compare > 0) {
	return _bintree_search_recursive(binTree, node->right, element);
    } else {
	return true;
    }
}
void _bintree_in_order_recursive(BinaryTree* binTree, BinaryTreeNode* node) {
    if (node == NULL) return;
    _bintree_in_order_recursive(binTree, node->left);
    binTree->print(node->data);
    _bintree_in_order_recursive(binTree, node->right);
}
void _bintree_pre_order_recursive(BinaryTree* binTree, BinaryTreeNode* node) {
    if (node == NULL) return;
    binTree->print(node->data);
    _bintree_pre_order_recursive(binTree, node->left);
    _bintree_pre_order_recursive(binTree, node->right);
}
void _bintree_post_order_recursive(BinaryTree* binTree, BinaryTreeNode* node) {
    if (node == NULL) return;
    _bintree_post_order_recursive(binTree, node->left);
    _bintree_post_order_recursive(binTree, node->right);
    binTree->print(node->data);
}
void _bintree_reverse_order_recursive(BinaryTree* binTree, BinaryTreeNode* node) {
    if (node == NULL) return;
    _bintree_reverse_order_recursive(binTree, node->right);
    binTree->print(node->data);
    _bintree_reverse_order_recursive(binTree, node->left);
}
bool _bintree_insert_replace_recursive(BinaryTree* binTree, BinaryTreeNode* node, void* element) {
    int compare = binTree->compare(node->data, element);
    if (compare < 0) {
	if (node->left == NULL) {
	    node->left = bintree_create_node(binTree->itemSize, element);
	    return true;
	} else {
	    return _bintree_insert_recursive(binTree,node->left, element);
	}
    } if (compare > 0) {
	if (node->right == NULL) {
	    node->right = bintree_create_node(binTree->itemSize, element);
	    return true;
	} else {
	    return _bintree_insert_recursive(binTree,node->right, element);
	}
    } else {
	bintree_set_node(node, binTree->itemSize, element);
    }
}
void _bintree_destroy_recursive(BinaryTree* binTree, BinaryTreeNode* node) {
    if (node == NULL) return;
    _bintree_destroy_recursive(binTree, node->left);
    _bintree_destroy_recursive(binTree, node->right);
    
    free(node->data);
    free(node);
    node = NULL;
    return;
}
