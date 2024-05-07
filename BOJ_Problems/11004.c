#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int *numbers = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    qsort(numbers, N, sizeof(int), compare);

    printf("%d\n", numbers[K - 1]);

    free(numbers);
    return 0;
}
