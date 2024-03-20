#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int p = n / m;
    int q = n % m;
    long long int ans = 1;
    
    for (int i = 0; i < m; i++) {
        if (q > 0) {
            ans *= (p + 1);
            q--;
        } else {
            ans *= p;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
