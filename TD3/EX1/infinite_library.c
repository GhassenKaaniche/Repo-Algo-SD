#include <stdio.h>
#include <stdlib.h>
#include "infinite_library.h"

static int max(int a, int b) {
    return a > b ? a : b;
}

static int height(Node *n) {
    return n ? n->height : 0;
}

static Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

static Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

static int getBalance(Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* insert(Node *node, int key) {
    if (!node) {
        Node *newNode = malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int search(Node *root, int key) {
    if (!root)
        return 0;
    if (root->key == key)
        return 1;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}