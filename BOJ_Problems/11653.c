#include <stdio.h>

void primeFactorization(int n) {
    
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d\n", i);
            n /= i;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
 
    if (N > 1) {
        primeFactorization(N);
    }

    return 0;
}
