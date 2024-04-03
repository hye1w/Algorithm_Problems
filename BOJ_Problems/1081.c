#include <stdio.h>

long long num[10] = { 0 };

void cal(long long number, long long sub, long long last) {
    if (number == 0) return;
    for (int i = 0; i < 10; i++)
        num[i] += (number / 10) * sub;
    for (int i = 0; i < number % 10; i++)
        num[i] += sub;
    num[0] -= sub;
    num[number % 10] += last + 1;
    cal(number / 10, sub * 10, last + sub * (number % 10));
}

int main(void) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    if (x != 0) x--;
    cal(x, 1, 0);
    long long sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum -= i * num[i];
        num[i] = 0;
    }

    cal(y, 1, 0);
    for (int i = 0; i <= 9; i++) {
        sum += i * num[i];
        num[i] = 0;
    }

    printf("%lld", sum);
    return 0;
}
