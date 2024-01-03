#include <stdio.h>
#include <stdlib.h>

typedef struct dot{
    int x;
    int y;
}dot;

int compare_num(int a, int b) {
    if(a>b) return 1;
    if(a<b) return -1;
    if(a==b) return 0;
}

int compare(const void *a, const void *b) {
    dot first = *(dot*)a;
    dot second = *(dot*)b;
    
    if(first.y == second.y) return compare_num(first.x, second.x);
    return compare_num(first.y, second.y);
}

int main() {
    int N;
    scanf("%d", &N);
    dot *dot_arr = (dot*)malloc(sizeof(dot)*N);
    
    for(int i=0; i<N; i++) {
        scanf("%d %d", &dot_arr[i].x, &dot_arr[i].y);
    }
    
    qsort(dot_arr, N, sizeof(dot), compare);
    for(int i=0; i<N; i++) {
        printf("%d %d\n", dot_arr[i].x, dot_arr[i].y);
    }
    free(dot_arr);
    
    return 0;
}
