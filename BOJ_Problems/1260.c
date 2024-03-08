#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001
#define MAX_M 10001

int graph[MAX_N][MAX_N]; 
int visited[MAX_N]; 
int queue[MAX_N]; 
int front = -1, rear = -1; 

void enqueue(int v) {
    if (rear == MAX_N - 1) return;
    queue[++rear] = v;
}

int dequeue() {
    if (front == rear) return -1; 
    return queue[++front];
}

void dfs(int v, int N) {
    printf("%d ", v);
    visited[v] = 1; 
    for (int i = 1; i <= N; i++) {
        if (graph[v][i] && !visited[i]) { 
            dfs(i, N); 
        }
    }
}

void bfs(int v, int N) {
    enqueue(v); 
    visited[v] = 1; 
    while (1) {
        int next = dequeue();
        if (next == -1) break; 
        printf("%d ", next);
        for (int i = 1; i <= N; i++) {
            if (graph[next][i] && !visited[i]) { 
                enqueue(i); 
                visited[i] = 1; 
            }
        }
    }
}

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    for (int i = 0; i < MAX_N; i++) {
        visited[i] = 0;
    }

    dfs(V, N);
    printf("\n");

    for (int i = 0; i < MAX_N; i++) {
        visited[i] = 0;
    }

    bfs(V, N);
    printf("\n");

    return 0;
}
