#include <stdio.h>
#include <stdlib.h>
 
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N;
    scanf("%d", &N);
 
    int ropes[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &ropes[i]);
    }
 
    qsort(ropes, N, sizeof(int), compare);
 
    int max_weight = 0;
    for (int i = 0; i < N; i++) {
        int weight = ropes[i] * (i + 1); 
        if (weight > max_weight) {
            max_weight = weight;
        }
    }

    printf("%d\n", max_weight);

    return 0;
}
