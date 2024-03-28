#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char board[N][M+1]; 

    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    int count = 0; 

    for (int i = 0; i < N; i++) {
        char pre = '/';
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '-') {
                if (board[i][j] != pre) {
                    count++;
                }
            }
            pre = board[i][j];
        }
    }

    for (int j = 0; j < M; j++) {
        char pre = '/';
        for (int i = 0; i < N; i++) {
            if (board[i][j] == '|') {
                if (board[i][j] != pre) {
                    count++;
                }
            }
            pre = board[i][j];
        }
    }

    printf("%d\n", count);

    return 0;
}
