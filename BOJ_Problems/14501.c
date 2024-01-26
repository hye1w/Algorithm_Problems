#include <stdio.h>

#define MAX_N 15

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    int T[MAX_N], P[MAX_N];
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &T[i], &P[i]);
    }

    int dp[MAX_N + 1] = {0};  

    for (int i = N - 1; i >= 0; --i) {
        int nextDay = i + T[i];

        dp[i] = max(dp[i + 1], (nextDay <= N) ? P[i] + dp[nextDay] : 0);
    }

    printf("%d\n", dp[0]);  

    return 0;
}
