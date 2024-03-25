#include <stdio.h>

long long int gcd(long long int a, long long int b) {
    while (b != 0) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long int lcm(long long int a, long long int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    long long int A, B;
    scanf("%lld %lld", &A, &B);
    
    long long int result = lcm(A, B);

    printf("%lld\n", result);
    return 0;
}
