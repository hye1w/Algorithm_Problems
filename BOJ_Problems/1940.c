#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    int start = 0;
    int end = N - 1;
    int count = 0;

    while (end > start) {
        if (arr[start] + arr[end] == M) {
            start++;
            end--;
            count++;
        } else if (arr[start] + arr[end] < M) {
            start++;
        } else {
            end--;
        }
    }

    printf("%d\n", count);

    free(arr);

    return 0;
}
