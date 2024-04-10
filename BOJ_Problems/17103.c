#include <stdio.h>

#define MAX_N 1000000

int is_prime[MAX_N + 1] = {0};

void save_prime() {
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (!is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = 1; 
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T); 

    save_prime(); 

    while (T--) {
        int N;
        scanf("%d", &N);

        int count = 0;

        for (int i = 2; i <= N / 2; ++i) {
            
            if (!is_prime[i] && !is_prime[N - i]) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
