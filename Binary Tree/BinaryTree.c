#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void buildTree(Node *root, int value, int height) {
    root->data = value;
    if (height <= 0) {
        root->left = NULL;
        root->right = NULL;
        return;
    }
    root->left = malloc(sizeof(Node));
    root->right = malloc(sizeof(Node));
    buildTree(root->left, value - height, height / 2);
    buildTree(root->right, value + height, height / 2);
}

void treeTraversal(const Node *root) {
    if (root == NULL) {
        return;
    }
    treeTraversal(root->left);
    printf("%d ", root->data);
    treeTraversal(root->right);
}

int countNode(const Node *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNode(root->left) + countNode(root->right);
}

void getChild(const Node *root, int curLevel, int childLevel) {
    if (root == NULL) {
        return;
    }

    if (curLevel >= childLevel) {
        printf("%d ", root->data);
    }

    getChild(root->left, curLevel + 1, childLevel);
    getChild(root->right, curLevel + 1, childLevel);
}

int main() {
    Node *root = malloc(sizeof(Node));
    int height = 4;
    buildTree(root, 1 << height, 1 << (height - 1));
    treeTraversal(root->left);
    printf("\nNumber of nodes: %d", countNode(root));
    // printf("\nChildren of 4:\n");
    // getChild(root, 0, 2);
}