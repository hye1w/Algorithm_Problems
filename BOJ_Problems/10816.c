#include <stdio.h>

int cards[20000001]; 

int main() {
    int N, M;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        cards[num + 10000000]++; 
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        printf("%d ", cards[num + 10000000]); 
    }

    return 0;
}
