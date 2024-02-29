#include <stdio.h>

int main() {
    int A, B, C;
    
    scanf("%d %d %d", &A, &B, &C);
    
    int secondLargest;
    if ((A >= B && A <= C) || (A <= B && A >= C))
        secondLargest = A;
    else if ((B >= A && B <= C) || (B <= A && B >= C))
        secondLargest = B;
    else
        secondLargest = C;
    
    printf("%d\n", secondLargest);
    
    return 0;
}
