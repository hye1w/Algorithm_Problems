#include <stdio.h>

int count_prime(int num) {
    int count = 0;
    for (int i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            count++;
            num /= i;
        }
    }
    if (num > 1) {
        count++;
    }
    return count;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int underprime = 0;
    for (int i = A; i <= B; i++) {
        int prime_factors = count_prime(i);
        if (prime_factors > 0 && count_prime(prime_factors) == 1) {
            underprime++;
        }
    }

    printf("%d\n", underprime);

    return 0;
}
