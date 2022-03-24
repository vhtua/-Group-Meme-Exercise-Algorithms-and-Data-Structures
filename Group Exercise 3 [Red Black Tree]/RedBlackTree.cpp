#include <iostream>
#include <string>

struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
};

typedef Node *NodePtr;

class RedBlackTree {
private:
    NodePtr root;
    NodePtr TNULL;

    void leftRotate(NodePtr x) {
        NodePtr y = x->right;
        x->right = y->left;

        if (y->left != TNULL) {
            y->left->parent = x;
        }

        else if (x == x->parent->left) {
            x->parent->left = y;
        }

        else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rightRotate(NodePtr x) {
        NodePtr y = x->left;
        x->left = y->right;

        if (y->right != TNULL) {
            y->right->parent = x;
        }

        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }

        else if (x == x->parent->right) {
            x->parent->right = y;
        }

        else {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;
    }

    NodePtr searchTreeHelper(NodePtr root, int key) {
        if (root == TNULL || key == root->data) {
            return root;
        }

        if (key < root->data) {
            return searchTreeHelper(root->left, key);
        }

        if (key > root->data) {
            return searchTreeHelper(root->right, key);
        }
    }

public:
    RedBlackTree() {
        TNULL = new Node;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

};