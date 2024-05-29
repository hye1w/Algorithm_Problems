#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int n, m;
char campus[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int cnt = 0;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    visited[x][y] = true;
    if (campus[x][y] == 'P') {
        cnt++;
    }
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !visited[new_x][new_y]) {
            if (campus[new_x][new_y] != 'X') {
                dfs(new_x, new_y);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", campus[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (campus[i][j] == 'I') {
                dfs(i, j);
            }
        }
    }

    if (cnt == 0) {
        printf("TT\n");
    } else {
        printf("%d\n", cnt);
    }

    return 0;
}
