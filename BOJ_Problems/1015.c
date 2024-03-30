#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int A_size;
    scanf("%d", &A_size);

    int A[A_size];
    for (int i = 0; i < A_size; i++) {
        scanf("%d", &A[i]);
    }

    int sorted_A[A_size];
    for (int i = 0; i < A_size; i++) {
        sorted_A[i] = A[i];
    }
    qsort(sorted_A, A_size, sizeof(int), compare);

    int P[A_size];

    for (int i = 0; i < A_size; i++) {
        for (int j = 0; j < A_size; j++) {
            if (A[i] == sorted_A[j]) {
                P[i] = j;
                sorted_A[j] = -1;
                break;
            }
        }
    }

    for (int i = 0; i < A_size; i++) {
        printf("%d ", P[i]);
    }
    printf("\n");

    return 0;
}
