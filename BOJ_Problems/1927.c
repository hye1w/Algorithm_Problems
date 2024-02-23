#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

void init_heap(MinHeap *heap) {
    heap->size = 0;
}

void insert(MinHeap *heap, int value) {
    int i;
    for (i = ++(heap->size); i != 1 && value < heap->arr[i / 2]; i /= 2) {
        heap->arr[i] = heap->arr[i / 2];
    }
    heap->arr[i] = value;
}

int delete_min(MinHeap *heap) {
    if (heap->size == 0) {
        return 0;  
    }

    int min_value = heap->arr[1];
    int last_value = heap->arr[(heap->size)--];

    int parent = 1;
    int child;

    while (parent * 2 <= heap->size) {
        child = parent * 2;
        if (child + 1 <= heap->size && heap->arr[child] > heap->arr[child + 1]) {
            child++;
        }
        if (last_value <= heap->arr[child]) {
            break;
        }
        heap->arr[parent] = heap->arr[child];
        parent = child;
    }
    heap->arr[parent] = last_value;

    return min_value;
}

int main() {
    MinHeap heap;
    init_heap(&heap);

    int N, x;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (x == 0) {
            printf("%d\n", delete_min(&heap));
        } else {
            insert(&heap, x);
        }
    }
    return 0;
}
