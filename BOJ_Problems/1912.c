#include <stdio.h>

int maxCal(int a, int b) {
    return (a > b) ? a : b;
}

int maxSum(int arr[], int size) {
    int max = arr[0];
    int maxFar = arr[0];

    for (int i = 1; i < size; i++) {
        max = maxCal(arr[i], max+ arr[i]);
        maxFar = maxCal(maxFar, max);
    }
    return maxFar;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxSum(arr, n);
    printf("%d\n", result);

    return 0;
}
