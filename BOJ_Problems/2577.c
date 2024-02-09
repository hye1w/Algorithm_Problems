#include <stdio.h>

int main() {
    int A, B, C;
    int result;
    int counts[10] = {0}; 

    scanf("%d %d %d", &A, &B, &C);

    result = A * B * C;

    while (result > 0) {
        int digit = result % 10; 
        counts[digit]++; // 
        result /= 10; // 
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", counts[i]);
    }
    return 0;
}
