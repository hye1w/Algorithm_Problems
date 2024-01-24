#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCost(int costs[][3], int n) {
    int dp[n][3];
 
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for (int i = 1; i < n; i++) {
        dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    return min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}

int main() {
    int N;
    scanf("%d", &N);

    int costs[N][3];

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &costs[i][0], &costs[i][1], &costs[i][2]);
    }

    int result = minCost(costs, N);
    printf("%d\n", result);

    return 0;
}
