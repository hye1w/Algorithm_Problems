#include <stdio.h>

int main(void) {
    int N=0;
    int k=0;
    int tmp=0;
    int x[10000] = {0, };
    scanf("%d %d", &N, &k);
    
    for(int i=0; i<N; i++) {
        scanf("%d", &x[i]);
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N-1; j++) {
            if(x[j+1] < x[j]) {
                tmp = x[j+1];
                x[j+1] = x[j];
                x[j] = tmp;
            }
        }
    }
    printf("%d", x[N-k]);
}
