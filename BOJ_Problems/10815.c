#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int target, int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return 1;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, M;
    scanf("%d", &N);
    
    int *cards = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i)
        scanf("%d", &cards[i]);

    qsort(cards, N, sizeof(int), compare);

    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int num;
        scanf("%d", &num);
        
        printf("%d ", binary_search(cards, num, 0, N - 1));
    }

    free(cards);

    return 0;
}
