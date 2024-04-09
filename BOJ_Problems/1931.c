#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    const int *x = *(const int **)a;
    const int *y = *(const int **)b;

    if (x[1] == y[1]) {
        return x[0] - y[0];
    }
    return x[1] - y[1];
}

int main() {
    int N;
    scanf("%d", &N); 

    int **time = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        time[i] = (int *)malloc(2 * sizeof(int));
    }
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &time[i][0], &time[i][1]);
    }

    qsort(time, N, sizeof(int *), compare);

    int cnt = 1;
    int end_time = time[0][1];
    for (int i = 1; i < N; i++) {
        if (time[i][0] >= end_time) {
            cnt++;
            end_time = time[i][1];
        }
    }

    printf("%d\n", cnt);

    for (int i = 0; i < N; i++) {
        free(time[i]);
    }
    free(time);

    return 0;
}
