#include <stdio.h>

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int function(int N, int K) {
    return factorial(N) / (factorial(K) * factorial(N - K));
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
     
    if(N < 1 || N > 10 || K < 0 || K > N) { 
        return 1;
    }

    printf("%d\n", function(N, K));
    return 0;
}
