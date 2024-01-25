#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    long long Sum[N + 1];
    Sum[0] = 0;
 
    for (int i = 1; i <= N; i++) {
        int num;
        scanf("%d", &num);
        Sum[i] = (Sum[i - 1] + num) % M;
    }

    int CalCount[M];  
    for (int i = 0; i < M; i++) {
        CalCount[i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        CalCount[Sum[i]]++;
    }

    long long count = CalCount[0]; 
    
    for (int i = 0; i < M; i++) {
        count += (long long)CalCount[i] * (CalCount[i] - 1) / 2;
    }

    printf("%lld\n", count);

    return 0;
}
