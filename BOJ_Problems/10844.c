#include <stdio.h>

#define MOD 1000000000

int main() {
    int N;
    scanf("%d", &N);

    int dp[101][10] = {0};

    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1] % MOD;
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][8] % MOD;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    int total = 0;
    for (int i = 0; i <= 9; ++i) {
        total = (total + dp[N][i]) % MOD;
    }

    printf("%d\n", total);

    return 0;
}
