#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    char A[N][M+1], B[N][M+1];
    for (int i = 0; i < N; i++)
        scanf("%s", A[i]);
    for (int i = 0; i < N; i++)
        scanf("%s", B[i]);
    
    void flip(int r, int c) {
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                A[i][j] = (A[i][j] == '0') ? '1' : '0'; 
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (A[i][j] != B[i][j]) {
                flip(i, j);
                count++;
            }
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) { 
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", count); 
    return 0;
}
