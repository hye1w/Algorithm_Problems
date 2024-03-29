#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    qsort(numbers, n, sizeof(int), compare);
    
    int median = numbers[(n - 1) / 2];
    
    printf("%d\n", median);
    
    return 0;
}
