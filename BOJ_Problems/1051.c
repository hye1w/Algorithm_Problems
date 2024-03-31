#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int d = min(N, M);

    int array[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &array[i][j]);
        }
    }

    int answer = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 1; k < d; k++) {
                if (i + k < N && j + k < M) {
                    int n = array[i][j];
                    if (n == array[i + k][j] && n == array[i][j + k] && n == array[i + k][j + k]) {
                        answer = max(answer, (k + 1) * (k + 1));
                    }
                }
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
