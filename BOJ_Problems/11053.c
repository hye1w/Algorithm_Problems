#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int Increase(int arr[], int n) {
    int lis[n];
    int max_lis = 1;
    
    for (int i = 0; i < n; ++i) {
        lis[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j])
                lis[i] = max(lis[i], lis[j] + 1);
        }
        max_lis = max(max_lis, lis[i]);
    }
    
    return max_lis;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d\n", Increase(arr, n));
    
    return 0;
}
