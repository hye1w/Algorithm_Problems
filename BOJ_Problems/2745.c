#include <stdio.h>
#include <string.h>
#include <math.h>

int chartoint(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

int main() {
    char N[100];
    int B, len, i;
    long long result = 0;

    scanf("%s %d", N, &B);
    len = strlen(N);

    for (i = 0; i < len; i++) {
        result += chartoint(N[i]) * pow(B, len - i - 1);
    }

    printf("%lld\n", result);

    return 0;
}
