#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* Find(Node* node, char value) {
    if (node == NULL || node->value == value) {
        return node;
    }

    Node* leftResult = Find(node->left, value);
    if (leftResult != NULL) {
        return leftResult;
    }
    return Find(node->right, value);
}

void buildTree(Node* root, char rootValue, char leftValue, char rightValue) {
    if (leftValue != '.') {
        root->left = createNode(leftValue);
        buildTree(root->left, leftValue, '.', '.');
    }

    if (rightValue != '.') {
        root->right = createNode(rightValue);
        buildTree(root->right, rightValue, '.', '.');
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%c", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c", root->value);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->value);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    char rootValue, leftValue, rightValue;
    scanf(" %c %c %c", &rootValue, &leftValue, &rightValue);
    Node* root = createNode(rootValue);
    buildTree(root, rootValue, leftValue, rightValue);

    for (int i = 1; i < N; i++) {
        scanf(" %c %c %c", &rootValue, &leftValue, &rightValue);
        Node* existingNode = Find(root, rootValue);
        buildTree(existingNode, rootValue, leftValue, rightValue);
    }

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    return 0;
}
