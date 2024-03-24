#include <stdio.h>
#include <stdbool.h>

void primenum(int M, int N) {
    bool prime[N+1];
    for (int p = 2; p <= N; p++)
        prime[p] = true;

    for (int p = 2; p * p <= N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = M; p <= N; p++) {
        if (prime[p])
            printf("%d\n", p);
    }
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
     
    if(M < 1 || N < M || N > 1000000) { 
        return 1;
    }

    primenum(M, N);
    return 0;
}
