#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int times[N];

    for (int i = 0; i < N; ++i) {
        scanf("%d", &times[i]);
    }

    qsort(times, N, sizeof(int), compare);

    int sum = 0;

    for (int i = 0; i < N; ++i) {
        sum += times[i] * (N - i);
    }

    printf("%d\n", sum);

    return 0;
}
