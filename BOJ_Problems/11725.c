#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100001

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* tree[MAX_NODES];
bool visited[MAX_NODES];
int answer[MAX_NODES];

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int s, int e) {
    Node* newNode = createNode(e);
    newNode->next = tree[s];
    tree[s] = newNode;

    newNode = createNode(s);
    newNode->next = tree[e];
    tree[e] = newNode;
}

void DFS(int n) {
    visited[n] = true;

    Node* current = tree[n];
    while (current != NULL) {
        int i = current->value;
        if (!visited[i]) {
            answer[i] = n;
            DFS(i);
        }
        current = current->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        tree[i] = NULL;
        visited[i] = false;
        answer[i] = 0;
    }

    for (int i = 1; i < N; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        addEdge(s, e);
    }
    DFS(1);

    for (int i = 2; i <= N; i++) {
        printf("%d\n", answer[i]);
    }

    return 0;
}
