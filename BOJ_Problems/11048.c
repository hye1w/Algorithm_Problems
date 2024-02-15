#include <stdio.h>

#define MAX_SIZE 1000

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    int N, M;
    int maze[MAX_SIZE][MAX_SIZE]; 
    int dp[MAX_SIZE][MAX_SIZE]; 

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &maze[i][j]);
        }
    }

    dp[0][0] = maze[0][0];
    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i-1][0] + maze[i][0]; 
    }
    for (int j = 1; j < M; ++j) {
        dp[0][j] = dp[0][j-1] + maze[0][j]; 
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            dp[i][j] = MAX(MAX(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + maze[i][j];
        }
    }

    printf("%d\n", dp[N-1][M-1]);

    return 0;
}
