#include <stdio.h>

int solve(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    return solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main() {
    int T;  
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        int n;
        scanf("%d", &n);

        printf("%d\n", solve(n));
    }
    return 0;
}
