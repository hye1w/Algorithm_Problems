#include <stdio.h>

int main() {
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    int reverseA = (A % 10) * 100 + ((A / 10) % 10) * 10 + (A / 100);
    int reverseB = (B % 10) * 100 + ((B / 10) % 10) * 10 + (B / 100);
    
    if (reverseA > reverseB)
        printf("%d\n", reverseA);
    else
        printf("%d\n", reverseB);
    
    return 0;
}
