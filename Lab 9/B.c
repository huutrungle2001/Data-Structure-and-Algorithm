#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert(Node *root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

Node *getNode(Node *root, int target) {
    // If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If the target is found, return the node
    if (root->key == target) {
        return root;
    }
    // If the target is less than the current node, search the left subtree
    else if (target < root->key) {
        return getNode(root->left, target);
    }
    // If the target is greater than the current node, search the right subtree
    else {
        return getNode(root->right, target);
    }

    return NULL;
}

void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

int main() {
    Node *root = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }

    postorder(root);
    return 0;
}
