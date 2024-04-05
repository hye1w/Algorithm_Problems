#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int cur = 0;
    for (int i = 0; i < k; i++) {
        cur += arr[i];
    }
    int answer = cur;
    for (int i = k; i < n; i++) {
        cur = cur + arr[i] - arr[i - k];
        if (cur > answer) {
            answer = cur;
        }
    }
    printf("%d\n", answer);

    return 0;
}
