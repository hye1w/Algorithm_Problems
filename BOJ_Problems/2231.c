#include <stdio.h>

int main() {
    int i, j, n, sum, p = 0 ;
    scanf("%d", &n);

    while (p < 10000000) {
        ++p;
        j = p;
        sum += j;
        
        for (i = j; i > 0; i = i / 10) 
            sum += i % 10;
        
        if (sum == n)
        {
            sum = p;
            break;
        }
        sum = 0;
    }

    printf("%d", sum);
    return 0;
} 
