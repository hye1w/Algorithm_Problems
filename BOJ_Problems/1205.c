#include <stdio.h>

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    if (n == 0) {
        printf("1\n");
    } else {
        int data[n + 1];
        for (int i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }
        data[n] = m;
        int size = n + 1;

        for (int i = size - 1; i > 0 && data[i] > data[i - 1]; i--) {
            int temp = data[i];
            data[i] = data[i - 1];
            data[i - 1] = temp;
        }

        int index = 1;
        for (int i = 0; i < size; i++) {
            if (data[i] == m) {
                index = i + 1;
                break;
            }
        }

        if (index > k) {
            printf("-1\n");
        } else {
            if (n == k && m == data[size - 1]) {
                printf("-1\n");
            } else {
                printf("%d\n", index);
            }
        }
    }

    return 0;
}
