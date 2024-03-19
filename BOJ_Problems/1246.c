#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int prices[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &prices[i]);
    }
    
    qsort(prices, M, sizeof(int), compare);
    
    int min_price = prices[0];
    int max_profit = 0;
    
    for (int i = 0; i < M; i++) {
        int potential_profit = (i + 1) * prices[i]; 
        if (potential_profit > max_profit && (i + 1) <= N) {  
            max_profit = potential_profit;
            min_price = prices[i];
        }
    }
    
    printf("%d %d\n", min_price, max_profit);
    
    return 0;
}
