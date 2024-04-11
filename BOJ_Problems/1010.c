#include <stdio.h>

int combination(int n, int m) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= (m - i);
        result /= (1 + i);
    }
    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, M;
        scanf("%d %d", &N, &M);
        int Max = (N > M) ? N : M;
        int Min = (N < M) ? N : M;
        
        int result = combination(N, M);
        printf("%d\n", result);
    }

    return 0;
}
