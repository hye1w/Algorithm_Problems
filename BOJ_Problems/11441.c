#include <stdio.h>

int main() {
    int N, M;
    scanf("%d", &N); 
    int A[N+1];
    int prefix_sum[N+1];  
    prefix_sum[0] = 0; 
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        prefix_sum[i] = prefix_sum[i-1] + A[i];
    }
    
    scanf("%d", &M); 
    
    for (int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", prefix_sum[end] - prefix_sum[start-1]);  
    }
    
    return 0;
}
