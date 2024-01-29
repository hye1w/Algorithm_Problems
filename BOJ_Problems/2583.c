#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX][MAX];

int dfs(int x, int y, int m, int n) {
    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) {
        return 0;
    }

    visited[x][y] = 1;
    int area = 1;
    area += dfs(x + 1, y, m, n);
    area += dfs(x - 1, y, m, n);
    area += dfs(x, y + 1, m, n);
    area += dfs(x, y - 1, m, n);

    return area;
}

void emptyArea(int m, int n, int rectangles[][4], int k) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        int x1 = rectangles[i][0];
        int y1 = rectangles[i][1];
        int x2 = rectangles[i][2];
        int y2 = rectangles[i][3];

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                visited[x][y] = 1;
            }
        }
    }

    int count = 0;
    int *areas = malloc(MAX * MAX * sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                areas[count++] = dfs(i, j, m, n);
            }
        }
    }
    printf("%d\n", count);

    if (count > 0) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (areas[i] > areas[j]) {
                    int temp = areas[i];
                    areas[i] = areas[j];
                    areas[j] = temp;
                }
            }
        }
        for (int i = 0; i < count; i++) {
            printf("%d ", areas[i]);
        }
    }
    free(areas);
}

int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);

    int rectangles[MAX][4];
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d", &rectangles[i][1], &rectangles[i][0], &rectangles[i][3], &rectangles[i][2]);
    }
    emptyArea(m, n, rectangles, k);

    return 0;
}
