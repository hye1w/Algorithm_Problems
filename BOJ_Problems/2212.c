#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int sensors[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &sensors[i]);
    }

    qsort(sensors, N, sizeof(int), compare);

    int intervals[N - 1];
    for (int i = 0; i < N - 1; i++) {
        intervals[i] = sensors[i + 1] - sensors[i];
    }

    qsort(intervals, N - 1, sizeof(int), compare);

    for (int i = 0; i < K - 1 && i < N - 1; i++) {
        intervals[N - 2 - i] = 0;
    }

    int totalLength = 0;
    for (int i = 0; i < N - 1; i++) {
        totalLength += intervals[i];
    }

    printf("%d\n", totalLength);

    return 0;
}
