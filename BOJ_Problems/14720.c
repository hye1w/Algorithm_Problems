#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int store[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &store[i]);
    }

    int drunk = 0;
    for (int i = 0; i < N; i++) {
        if (store[i] == drunk % 3) {
            drunk++;
        }
    }

    printf("%d\n", drunk);

    return 0;
}
