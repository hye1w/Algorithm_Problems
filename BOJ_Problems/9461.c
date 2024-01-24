#include <stdio.h>

long long pado[101];

long long P(int n) {
    if (n == 1 || n == 2 || n == 3) {
        return 1;
    }
    
    if (pado[n] != 0) {
        return pado[n];
    }
    
    pado[n] = P(n - 2) + P(n - 3);
    return pado[n];
}

int main() {
    int T;
    scanf("%d", &T);

    pado[1] = pado[2] = pado[3] = 1;

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        
        printf("%lld\n", P(N));
    }

    return 0;
}
