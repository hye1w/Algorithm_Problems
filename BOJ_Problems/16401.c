#include <stdio.h>

#define MAX_N 1000001

long long countPieces(long long lengths[], int n, long long length) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        count += lengths[i] / length;
    }
    return count;
}

int main() {
    int M, N;
    long long lengths[MAX_N];
    
    scanf("%d %d", &M, &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%lld", &lengths[i]);
    }
    
    long long left = 1, right = 1000000000;
    long long result = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long pieces = countPieces(lengths, N, mid);
        
        if (pieces >= M) { 
            result = mid;
            left = mid + 1;
        } else { 
            right = mid - 1;
        }
    }
    
    printf("%lld\n", result);
    
    return 0;
}
