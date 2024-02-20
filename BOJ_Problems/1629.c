#include <stdio.h>

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long A, B, C;
    
    scanf("%lld %lld %lld", &A, &B, &C);
    
    long long result = mod_exp(A, B, C);
    printf("%lld\n", result);
    
    return 0;
}
