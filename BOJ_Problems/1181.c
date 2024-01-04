#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word {
    char arr[51];
    int len;
}word;

int compare(const void *a, const void *b) {
    word *first = (word*)a;
    word *second = (word*)b;
    
    if(first -> len < second -> len)
        return -1;
    else if(first -> len == second -> len)
        return strcmp(first -> arr, second -> arr);
    else 
        return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    word *list = (word*)malloc(sizeof(word)*N);
    
    for(int i=0; i<N; i++)
    {
        scanf("%s", list[i].arr);
        list[i].len = (int)strlen(list[i].arr);
    }
    
    qsort(list, N, sizeof(word), compare);
    
    for(int i=0; i<N; i++)
    {
        if(strcmp(list[i].arr, list[i+1].arr)!=0)
        {
            printf("%s\n", list[i].arr);
        }  
    }
}
