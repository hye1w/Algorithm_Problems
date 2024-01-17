#include <stdio.h>

typedef struct Data{
    int *arr;
    int front;
    int size;
    int max_size;
} DATA;

void makeData(DATA *d, int size){
    d->arr = (int *)calloc(size,sizeof(int));
    d->front = 0;
    d->size = 0;
    d->max_size = size;
}
void pushFront(DATA *d, int num){
    if(d->size!=0){
        if(d->front==0){
            d->front = d->max_size-1;
        }else{
            d->front--;
        }
    }
    d->arr[d->front]=num;
    d->size++;
}
void pushBack(DATA *d, int num){
    d->arr[(d->front+d->size++)%d->max_size]=num;    
}
int popFront(DATA *d){
    int ret = -1;
    if(d->size != 0){
        ret = d->arr[d->front];
        d->front = (d->front+1)%d->max_size;
        d->size--;
    }
    return ret;
}
int popBack(DATA *d){
    int ret = -1;
    if(d->size !=0){
        ret = d->arr[(d->front + --d->size)%d->max_size];
    }
    return ret;
}
int sizeData(DATA *d){
    int ret = d->size;
    return ret;
}
int isEmptyData(DATA *d){
    int ret = (d->size)? 0: 1;
    return ret;
}
int frontData(DATA *d){
    int ret = -1;
    if(d->size != 0){
        ret = d->arr[d->front];
    }
    return ret;
}
int backData(DATA *d){
    int ret = -1;
    if(d->size !=0){
        ret = d->arr[(d->front + d->size -1)%d->max_size];
    }
    return ret;
}

int main(){
    int N;
    scanf("%d",&N);
    
    DATA *deq = (DATA *)malloc(sizeof(DATA));
    makeData(deq,N);
    
    while(N--){
        int com;
        scanf("%d",&com);
        int val;
        
        switch(com){
            case 1:
                scanf("%d",&val); 
                pushFront(deq, val);
                break;
            case 2:
                scanf("%d",&val);
                pushBack(deq, val);
                break;
            case 3:
                printf("%d\n",popFront(deq));
                break;
            case 4:
                printf("%d\n",popBack(deq));
                break;
            case 5:
                printf("%d\n",sizeData(deq));
                break;
            case 6:
                printf("%d\n",isEmptyData(deq));
                break;
            case 7:
                printf("%d\n",frontData(deq));
                break;
            case 8:
                printf("%d\n",backData(deq));
                break;
        }
    }
    return 0;
}
