#include <stdio.h>

void josephus(int n, int k) {
    int i, index = 0;
    int arr[5000];
    for (i = 0; i < n; i++)
        arr[i] = i + 1;

    printf("<");
    for (i = 0; i < n; i++) {
        index = (index + k - 1) % (n - i);
        if (i == n - 1)
            printf("%d", arr[index]);
        else
            printf("%d, ", arr[index]);
        for (int j = index; j < n - i - 1; j++)
            arr[j] = arr[j + 1];
    }
    printf(">");
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    josephus(n, k);
    return 0;
}
