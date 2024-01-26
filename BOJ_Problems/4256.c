#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* buildTree(int* preorder, int* inorder, int start, int end, int* preIndex) {
    if (start > end) {
        return NULL;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = preorder[*preIndex];
    newNode->left = newNode->right = NULL;

    (*preIndex)++;

    if (start == end) {
        return newNode;
    }

    int inIndex;
    for (inIndex = start; inIndex <= end; inIndex++) {
        if (inorder[inIndex] == newNode->data) {
            break;
        }
    }

    newNode->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    newNode->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return newNode;
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int preorder[n];
        int inorder[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &preorder[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &inorder[i]);
        }

        int preIndex = 0;
        Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

        postorder(root);
        printf("\n");
    }

    return 0;
}
