#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int numbers[N];
    int Sum[N + 1];  
 
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    Sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        Sum[i] = Sum[i - 1] + numbers[i - 1];
    }

    for (int k = 0; k < M; k++) {
        int i, j;
        scanf("%d %d", &i, &j);

        printf("%d\n", Sum[j] - Sum[i - 1]);
    }

    return 0;
}
