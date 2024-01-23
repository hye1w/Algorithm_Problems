#include <stdio.h>

#define MOD 15746

int main() {
    int N;
    scanf("%d", &N);

    int dp[1000001];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    printf("%d\n", dp[N]);

    return 0;
}
