#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);

    int count = 0;
    while (X > 0) {
        if (X % 2 == 1) { 
            count++;
        }
        X /= 2;  
    }

    printf("%d\n", count);

    return 0;
}
