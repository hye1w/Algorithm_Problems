#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1001

int N, A, B, M;
int relation[MAX_N][MAX_N];
bool visited[MAX_N];
int cnt = 0, ans = -1;

void DFS(int v) {
    visited[v] = true;

    if (v == B) {
        ans = cnt;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (relation[v][i] && !visited[i]) {
            cnt++;
            DFS(i);
        }
    }
    cnt--;
}

int main() {
    scanf("%d", &N);
    scanf("%d %d", &A, &B);
    scanf("%d", &M);

    for (int i = 1; i <= N; i++) {
        visited[i] = false;
        for (int j = 1; j <= N; j++) {
            relation[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        relation[x][y] = relation[y][x] = 1;
    }

    DFS(A);

    printf("%d\n", ans);

    return 0;
}
