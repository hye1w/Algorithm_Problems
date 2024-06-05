#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int M[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &M[i]);
    }
    
    int ans[N];
    for (int i = 0; i < N; ++i) {
        ans[i] = 0;
    }

    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (cnt == M[i] && ans[j] == 0) {
                ans[j] = i + 1;
                break;
            } else if (ans[j] == 0) {
                cnt++;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
