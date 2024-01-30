#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N], B[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    qsort(A, N, sizeof(int), compare);

    qsort(B, N, sizeof(int), compare);
    for (int i = 0; i < N / 2; i++) {
        int temp = B[i];
        B[i] = B[N - i - 1];
        B[N - i - 1] = temp;
    }

    long long S = 0;
    for (int i = 0; i < N; i++) {
        S += (long long)A[i] * B[i];
    }

    printf("%lld\n", S);

    return 0;
}
