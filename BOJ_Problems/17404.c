#include <stdio.h>

#define MAX 1000
#define INF 1000000000

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    int house[MAX][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &house[i][j]);
        }
    }

    int result = INF;
    for (int i = 0; i < 3; i++) {
        int dp[MAX][3];
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 3; k++) {
                dp[j][k] = INF;
            }
        }

        dp[0][i] = house[0][i];

        for (int j = 1; j < N; j++) {
            dp[j][0] = house[j][0] + min(dp[j-1][1], dp[j-1][2]);
            dp[j][1] = house[j][1] + min(dp[j-1][0], dp[j-1][2]);
            dp[j][2] = house[j][2] + min(dp[j-1][0], dp[j-1][1]);
        }

        for (int k = 0; k < 3; k++) {
            if (i != k) {
                result = min(result, dp[N-1][k]);
            }
        }
    }
    printf("%d\n", result);

    return 0;
}
