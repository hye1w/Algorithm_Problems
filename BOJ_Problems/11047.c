#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int *coins = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &coins[i]);
    }

    int count = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) break; 
        
        int numCoins = K / coins[i];
         
        count += numCoins;
         
        K -= numCoins * coins[i];
    }
    printf("%d\n", count);

    free(coins);

    return 0;
}
