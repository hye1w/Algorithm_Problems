#include <stdio.h>

long long countPinary(int n) {
    long long dp[91];
    
    dp[1] = 1; 
    dp[2] = 1; 
    
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%lld\n", countPinary(n));
    
    return 0;
}
