#include <stdio.h>

int main() {
    int n = 0;
    long long sum = 1;
    scanf("%d", &n);
    
    for(int i = n; i > 0; i--) {
        sum *= i;
    }
    
    printf("%lld", sum);
    return 0;
} 
