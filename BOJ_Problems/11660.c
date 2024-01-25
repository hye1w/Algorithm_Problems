#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int table[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    int Sum[N + 1][N + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            Sum[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            Sum[i][j] = table[i - 1][j - 1] + Sum[i - 1][j] + Sum[i][j - 1] - Sum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int result = Sum[x2][y2] - Sum[x1 - 1][y2] - Sum[x2][y1 - 1] + Sum[x1 - 1][y1 - 1];
        printf("%d\n", result);
    }

    return 0;
}
