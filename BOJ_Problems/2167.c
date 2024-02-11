#include <stdio.h>

#define MAX_N 300
#define MAX_M 300

int main() {
    int N, M;
    int arr[MAX_N + 1][MAX_M + 1]; 
    int dp[MAX_N + 1][MAX_M + 1]; 

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &arr[i][j]);
            dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    int K;
    scanf("%d", &K);

    for (int k = 0; k < K; ++k) {
        int i, j, x, y;
        scanf("%d %d %d %d", &i, &j, &x, &y);
        int sum = dp[x][y] - dp[i-1][y] - dp[x][j-1] + dp[i-1][j-1];
        printf("%d\n", sum);
    }
    return 0;
}
