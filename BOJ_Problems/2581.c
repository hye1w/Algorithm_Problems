#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) return 0; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1; 
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int sum = 0, min_prime = -1;
    for (int i = M; i <= N; i++) {
        if (is_prime(i)) {
            sum += i;
            if (min_prime == -1 || i < min_prime) {
                min_prime = i;
            }
        }
    }

    if (min_prime == -1) {
        printf("-1\n");
    } else {
        printf("%d\n%d\n", sum, min_prime);
    }

    return 0;
}
