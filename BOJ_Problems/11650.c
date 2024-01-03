#include <stdio.h>
#include <stdlib.h>

typedef struct dot{
    int x;
    int y;
}dot;

int compare(const void *a, const void *b) {
    dot first = *(dot*)a;
    dot second = *(dot*)b;
    
    if(first.x > second.x) return 1;
    else if(first.x < second.x) return -1;
    else {
        if(first.y > second.y) return 1;
        else return -1;
    } return 0;
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
