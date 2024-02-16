#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);
bool is_palindrome(int num);

int main() {
    int N;
    scanf("%d", &N);

    for (int i = N;; ++i) {
        if (is_prime(i) && is_palindrome(i)) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}

bool is_prime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool is_palindrome(int num) {
    int original = num;
    int reverse = 0;

    while (num > 0) {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }

    return original == reverse; 
}
