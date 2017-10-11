//
// Created by Vladislav Raspopin on 10.10.17.
//
#ifndef UNTITLED2_NODE_H
#define UNTITLED2_NODE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeElem
{
    struct TreeElem* left_;
    struct TreeElem* right_;
    char* data_;

} TreeElem;


int compare(char* data_in_tree, char* str);
TreeElem* find_elem_tree(char* value, TreeElem* root);
TreeElem* find_parent_tree(char* value, TreeElem* root);
TreeElem* find_parent_tree_new_elem(char* value, struct TreeElem* root);
void delete_elem(TreeElem* elem, TreeElem* root);
void remove_elem_tree(char* value, TreeElem* root);
void delete_tree(TreeElem* root);
TreeElem* new_tree_elem(char* value, TreeElem* root);

#endif //UNTITLED2_NODE_H
