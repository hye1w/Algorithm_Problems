#include <stdio.h>
#include <math.h>

int main() {
    long long N;
    scanf("%lld", &N);
    
    long long open_windows = (long long)sqrt(N);
    
    printf("%lld\n", open_windows);
    
    return 0;
}
