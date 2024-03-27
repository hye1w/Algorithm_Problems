#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);

    int wines[n + 1];
    int dp[n + 1];    

    for (int i = 1; i <= n; i++) {
        scanf("%d", &wines[i]);
    }

    dp[0] = 0;
    dp[1] = wines[1];
    dp[2] = wines[1] + wines[2]; 
    
    for (int i = 3; i <= n; i++) {
        dp[i] = MAX(dp[i - 1], MAX(dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i]));
    }

    printf("%d\n", dp[n]);

    return 0;
}
