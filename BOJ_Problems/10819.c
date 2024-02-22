#include <stdio.h>
#include <stdlib.h>

int max_sum = -1;

int abs(int x) {
    return (x < 0) ? -x : x;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void find_max_sum(int* arr, int start, int end, int N) {
    if (start == end) {
        int sum = 0;
        for (int i = 0; i < N - 1; ++i) {
            sum += abs(arr[i] - arr[i + 1]);
        }
        if (sum > max_sum) {
            max_sum = sum;
        }
    } else {
        for (int i = start; i <= end; ++i) {
            swap(&arr[start], &arr[i]);
            find_max_sum(arr, start + 1, end, N);
            swap(&arr[start], &arr[i]); 
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    find_max_sum(arr, 0, N - 1, N);

    printf("%d\n", max_sum);

    free(arr);
    
    return 0;
}
