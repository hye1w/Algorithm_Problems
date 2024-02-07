#include <stdio.h>

#define MAX_SIZE 500

int n, m;
int canvas[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y) {
    visited[x][y] = 1;
    int area = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny) && canvas[nx][ny] && !visited[nx][ny])
            area += dfs(nx, ny);
    }
    return area;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &canvas[i][j]);
            visited[i][j] = 0;
        }
    }

    int paints = 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (canvas[i][j] && !visited[i][j]) {
                paints++;
                maxArea = max(maxArea, dfs(i, j));
            }
        }
    }

    printf("%d\n%d\n", paints, maxArea);

    return 0;
}
