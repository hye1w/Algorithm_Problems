#include <stdio.h>

int memoization[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (memoization[a][b][c] != 0)
        return memoization[a][b][c];

    if (a < b && b < c)
        return memoization[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else
        return memoization[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main() {
    int a, b, c;

    while (1) {
        scanf("%d %d %d", &a, &b, &c);

        if (a == -1 && b == -1 && c == -1)
            break;

        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }

    return 0;
}
