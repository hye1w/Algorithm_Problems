#include <stdio.h>
#include <math.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long obN[64];
    int index = 0;
    while (n > 0) {
        obN[index++] = n % 2;
        n /= 2;
    }

    long long t = 1, ans = 0;
    for (int i = 0; i < index; ++i) {
        ans += obN[i] * t;
        t *= 3;
    }

    printf("%lld\n", ans);
    return 0;
}
