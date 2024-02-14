#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    int *leaks = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &leaks[i]);
    }

    qsort(leaks, N, sizeof(int), compare);

    int count = 1; 
    int start_point = leaks[0]; 

    for (int i = 1; i < N; ++i) {
        if (leaks[i] - start_point + 1 <= L) {
            continue;
        } else { 
            count++;
            start_point = leaks[i];
        }
    }

    printf("%d\n", count);

    free(leaks); 

    return 0;
}
