#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

typedef struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = 0;
    dq->rear = 0;
}

bool isEmpty(Deque *dq) {
    return dq->front == dq->rear;
}

bool isFull(Deque *dq) {
    return (dq->rear + 1) % MAX_SIZE == dq->front;
}

void pushFront(Deque *dq, int x) {
    if (isFull(dq)) {
        printf("-1\n");
        return;
    }
    dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    dq->arr[dq->front] = x;
}

void pushBack(Deque *dq, int x) {
    if (isFull(dq)) {
        printf("-1\n");
        return;
    }
    dq->arr[dq->rear] = x;
    dq->rear = (dq->rear + 1) % MAX_SIZE;
}

int popFront(Deque *dq) {
    if (isEmpty(dq)) {
        return -1;
    }
    int res = dq->arr[dq->front];
    dq->front = (dq->front + 1) % MAX_SIZE;
    return res;
}

int popBack(Deque *dq) {
    if (isEmpty(dq)) {
        return -1;
    }
    dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return dq->arr[dq->rear];
}

int size(Deque *dq) {
    return (dq->rear - dq->front + MAX_SIZE) % MAX_SIZE;
}

int front(Deque *dq) {
    if (isEmpty(dq)) {
        return -1;
    }
    return dq->arr[dq->front];
}

int back(Deque *dq) {
    if (isEmpty(dq)) {
        return -1;
    }
    return dq->arr[(dq->rear - 1 + MAX_SIZE) % MAX_SIZE];
}

int main() {
    int N;
    scanf("%d", &N);

    Deque dq;
    initDeque(&dq);

    while (N--) {
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0) {
            int X;
            scanf("%d", &X);
            pushFront(&dq, X);
        } else if (strcmp(command, "push_back") == 0) {
            int X;
            scanf("%d", &X);
            pushBack(&dq, X);
        } else if (strcmp(command, "pop_front") == 0) {
            printf("%d\n", popFront(&dq));
        } else if (strcmp(command, "pop_back") == 0) {
            printf("%d\n", popBack(&dq));
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&dq));
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", isEmpty(&dq));
        } else if (strcmp(command, "front") == 0) {
            printf("%d\n", front(&dq));
        } else if (strcmp(command, "back") == 0) {
            printf("%d\n", back(&dq));
        }
    }

    return 0;
}
