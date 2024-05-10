#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    char A[51], B[51];
    scanf("%s %s", A, B);
    
    int len_A = strlen(A);
    int len_B = strlen(B);
    
    int min_diff = 50; // 초기 최소 차이 값을 매우 큰 값으로 설정
    for (int i = 0; i <= len_B - len_A; i++) {
        int diff = 0;
        for (int j = 0; j < len_A; j++) {
            if (A[j] != B[i + j]) {
                diff++;
            }
        }
        min_diff = min(min_diff, diff);
    }
    
    printf("%d\n", min_diff);
    
    return 0;
}
