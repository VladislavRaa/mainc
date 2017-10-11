#include "node.h"

int compare(char* data_in_tree, char* str)
{
    if (strcmp(data_in_tree, str) <= 0) {
        return 1;
    }
    return 0;
}

TreeElem* find_elem_tree(char* value, TreeElem* root)
{
    if (root == NULL) {
        return NULL;
    }
    TreeElem* elem = NULL;
    while (root) {
        if (strcmp(root->data_, value) == 0) {
            return root;
        }
        if (compare(root->data_, value)) {
            root = root->right_;
        } else
            root = root->left_;
        elem = root;
    }
    return elem;
}

TreeElem* find_parent_tree(char* value, TreeElem* root)
{
    if (root->data_ == value) {
        return 0;
    }

    TreeElem* parent = NULL;

    while (root != 0) {
        parent = root;
        if (compare(root->data_, value)) {
            root = root->right_;
        } else root = root->left_;
        if (root!=0 && strcmp(root->data_, value) == 0) {
            return parent;
        }
    }
    return root;
}
TreeElem* find_parent_tree_new_elem(char* value, struct TreeElem* root)
{
    TreeElem* parent = NULL;
    while (root != 0) {
        parent = root;
        if (compare(root->data_, value)) {
            root = root->right_;
        } else root = root->left_;
    }
    return parent;
}
void delete_elem(TreeElem* elem, TreeElem* root)
{
    if (root == NULL && elem == root) {
        return;
    }

    if (elem->right_ == NULL && elem->left_ == NULL) {
        TreeElem* parent = find_parent_tree(elem->data_, root);
        free(elem->data_);
        if (parent->right_ == elem) {
            parent->right_ = NULL;
            free(elem);
            return;
        }
        parent->left_ = NULL;
        free(elem);
        return;
    }

    if (elem->right_ == NULL) {
        TreeElem* parent = find_parent_tree(elem->data_, root);
        free(elem->data_);
        if (parent->right_ == elem) {
            parent->right_ = elem->left_;
            free(elem);
            return;
        }
        parent->left_ = elem->left_;
        free(elem);
        return;
    }

    if (elem->left_ == NULL) {
        TreeElem* parent = find_parent_tree(elem->data_, root);
        free(elem->data_);
        if (parent->right_ == elem) {
            parent->right_ = elem->right_;
            free(elem);
            return;
        }
        parent->left_ = elem->right_;
        free(elem);
        return;
    }

    TreeElem* elem_right = elem->right_;

    while (elem_right->left_) {
        elem_right = elem_right->left_;
    }
    TreeElem* parent = find_parent_tree(elem_right->data_, root);
    free(elem->data_);
    elem->data_ = elem_right->data_;
    if (parent->right_ == elem_right) {
        parent->right_ = elem_right->right_;
        free(elem_right);
        return;
    }
    parent->left_ = elem_right->right_;
    free(elem_right);
    return;
}

void remove_elem_tree(char* value, TreeElem* root)
{
    if (root == NULL) {
        return;
    }
    TreeElem* elem = find_elem_tree(value, root);
    if (elem == NULL) {
        printf("no element %s\n", value);
        return;
    }
    TreeElem* parent = find_parent_tree(value, root);
    if (parent == 0) {
        if ((root->right_ == NULL) && (root->left_ == NULL)) {
            free(root->data_);
            root->data_ = 0;
            return;
        }
        if (root->right_ == NULL) {
            free(root->data_);
            TreeElem* del_elem = root->left_;
            root->data_ = root->left_->data_;
            root->right_ = root->left_->right_;
            root->left_ = root->left_->left_;
            free(del_elem);
            return;
        }
        if (root->left_ == NULL) {
            free(root->data_);
            TreeElem* del_elem = root->right_;
            root->data_ = root->right_->data_;
            root->left_ = root->right_->left_;
            root->right_ = root->right_->right_;
            free(del_elem);
            return;
        }
        TreeElem* root_right = root->right_;
        while (root_right->left_) {
            root_right = root_right->left_;
        }

        TreeElem* parent = find_parent_tree(root_right->data_, root);
        free(root->data_);
        root->data_ = root_right->data_;

        if (parent->right_ == root_right) {
            parent->right_ = root_right->right_;
            free(root_right);
            return;
        }
        parent->left_ = root_right->right_;
        free(root_right);
        return;
    }
    delete_elem(elem, root);
    
}

void delete_tree(TreeElem* root) {
    while(1) {
        if (root->data_ == NULL) {
            free(root);
            return;
        }
        remove_elem_tree(root->data_, root);
    }
}

TreeElem* new_tree_elem(char* value, TreeElem* root) {

    if (find_elem_tree(value, root) != NULL) {
        return 0;
    }

    TreeElem* parent = NULL;

    if (root != NULL) {
        parent = find_parent_tree_new_elem(value, root);
    }

    TreeElem* new_elem = (TreeElem*) malloc(sizeof(TreeElem));

    if (new_elem == NULL) {
        printf("new_tree_elem: could not allocate memory for the pointer on TreeElem\n");
        return 0;
    }

    if (parent == NULL) {
        new_elem->data_ = malloc((strlen(value) + 1) * sizeof(char));
        if (new_elem->data_ == NULL) {
            printf("new_tree_elem: failed to allocate memory\n");
            return 0;
        }
        snprintf(new_elem->data_, strlen(value) + 1, "%s", value);
        new_elem->right_ = NULL;
        new_elem->left_ = NULL;
        return new_elem;
    }

    if (compare(parent->data_, value)) {
        parent->right_ = new_elem;
    } else {
        parent->left_ = new_elem;
    }

    new_elem->data_ = malloc((strlen(value) + 1) * sizeof(char));

    if (new_elem->data_ == NULL) {
        printf("new_tree_elem: Could not allocate memory for string storage");
        return 0;
    }

    snprintf(new_elem->data_, strlen(value) + 1, "%s", value);

    new_elem->right_ = NULL;
    new_elem->left_ = NULL;

    return new_elem;
}