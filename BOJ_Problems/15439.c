#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int combinations = N * (N - 1);
    printf("%d\n", combinations);

    return 0;
}
