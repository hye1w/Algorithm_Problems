#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int divisors[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &divisors[i]);
    }

    int min = divisors[0];
    int max = divisors[0];
    for (int i = 1; i < n; i++) {
        if (divisors[i] < min) {
            min = divisors[i];
        }
        if (divisors[i] > max) {
            max = divisors[i];
        }
    }

    printf("%d\n", min * max);

    return 0;
}
