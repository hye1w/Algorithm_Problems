#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    int *A, *B, *C;
    int *queue_index, *output;
    
    scanf("%d", &N);
    A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
    
    B = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i)
        scanf("%d", &B[i]);
    
    scanf("%d", &M);
    C = (int*)malloc(M * sizeof(int));
    for (int i = 0; i < M; ++i)
        scanf("%d", &C[i]);

    queue_index = (int*)malloc(N * sizeof(int));
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == 0)
            queue_index[count++] = i;
    }

    output = (int*)malloc((count + M) * sizeof(int));
    for (int i = count - 1; i >= 0; --i)
        output[count - 1 - i] = B[queue_index[i]];
    for (int i = 0; i < M; ++i)
        output[count + i] = C[i];

    for (int i = 0; i < M; ++i)
        printf("%d ", output[i]);
    printf("\n");

    free(A);
    free(B);
    free(C);
    free(queue_index);
    free(output);

    return 0;
}
