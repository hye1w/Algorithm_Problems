#include <stdio.h>

int isHan(int num) {
    if (num < 100) {
        return 1;  
    }

    int digit1 = num % 10;
    int digit2 = (num / 10) % 10;
    int digit3 = num / 100;

    return (digit3 - digit2) == (digit2 - digit1);
}

int countHans(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (isHan(i)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    int result = countHans(N);
    printf("%d\n", result);

    return 0;
}
