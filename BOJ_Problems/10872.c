#include <stdio.h>

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int N;
    scanf("%d", &N);
    
    if(N < 0) {
        printf("1\n");
        return 0;
    }

    printf("%d\n", factorial(N));
    return 0;
}
