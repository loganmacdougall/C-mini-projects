#include"dictionary.h"

Dictionary* dict_initialize(int (*compare)(void*, void*), void (*print)(void*)) {
  Dictionary* dict = malloc(sizeof(Dictionary));
  dict->tree = bintree_initialize(sizeof(Pair), "Pair", compare, print);

  return dict;
}

bool dict_insert(Dictionary* dict, void* key, void* value) {
    if (dict == NULL) return false;
    if (key == NULL) return false;
    if (value == NULL) return false;

    Pair* pair   = malloc(sizeof(Pair));
    pair->first  = key;
    pair->second = value;

    return bintree_insert_replace(dict->tree, pair);
}
void* dict_get(Dictionary* dict, void* key) {
    if (dict == NULL) return false;
    if (key == NULL) return false;

    Pair* key_as_pair  = malloc(sizeof(Pair));
    key_as_pair->first = key;
    key_as_pair->second = NULL;

    return _dict_get_recursive(dict->tree, key_as_pair, dict->tree->top);
}
ArrayList* dict_key_list(Dictionary* dict, int keySize) {
    ArrayList* list = alist_initialize(10, keySize, "Key");
    _dict_key_list_recursive(dict->tree, list, dict->tree->top);
    return list;
}
bool dict_contains(Dictionary* dict, void* key) {
    Pair* key_as_pair  = malloc(sizeof(Pair));
    key_as_pair->first = key;
    key_as_pair->second = NULL;

    return bintree_search(dict->tree, key_as_pair);
}
bool dict_destroy(Dictionary* dict) {
    if (dict == NULL) return false;
    bintree_destroy(dict->tree);
    free(dict);
    dict = NULL;

    return true;
}

void* _dict_get_recursive(BinaryTree* tree, Pair* key, BinaryTreeNode* node) {
    if (node == NULL) return NULL;
    int compare = tree->compare(node->data, key);
    if (compare < 0) {
	_dict_get_recursive(tree, key, node->left);
    } else if (compare > 0) {
	_dict_get_recursive(tree, key, node->right);
    } else {
	return ((Pair*) node->data)->second;
    }
}
void _dict_key_list_recursive(BinaryTree* tree, ArrayList* list, BinaryTreeNode* node) {
    if (node == NULL) return;
    _dict_key_list_recursive(tree, list, node->left);
    alist_add(list,((Pair*) node->data)->first);
    _dict_key_list_recursive(tree, list, node->right);
}
