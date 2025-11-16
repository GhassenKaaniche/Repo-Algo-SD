typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

Node* insert(Node *node, int key);
int search(Node *root, int key);