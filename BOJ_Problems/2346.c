#include <stdio.h>
#include <stdlib.h>

typedef struct balloon {
    int data;
    int index;
    int flag;
    struct balloon *prev;
    struct balloon *next;
} balloon;

int main() {
    int N, i, k, cnt = 0, mid, total = 0;
    balloon *new, *p;
    balloon *front = NULL, *rear = NULL, *present = NULL;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &k);

        new = (balloon *)malloc(sizeof(balloon));
        if (new == NULL)
            return -1;
        new->data = k;
        new->index = i + 1;
        new->flag = 0;

        if (i == 0)
            front = new;
        else if (i == N - 1) {
            rear = new;
            rear->next = front;
            front->prev = rear;
        }
        if (i != 0) {
            present->next = new;
            new->prev = present;
        }
        present = new;
    }
    p = front;

    while (1) {
        printf("%d ", p->index);
        p->flag = 1;
        cnt = 0;
        mid = p->data;
        total += 1;

        if (total == N)
            break;

        if (p->data > 0) {
            while (1) {
                p = p->next;
                if (p->flag == 0)
                    cnt += 1;
                if (cnt == mid)
                    break;
            }
        } else if (p->data < 0) {
            while (1) {
                p = p->prev;
                if (p->flag == 0)
                    cnt -= 1;

                if (cnt == mid)
                    break;
            }
        }
    }

    p = front;
    do {
        balloon *temp = p;
        p = p->next;
        free(temp);
    } while (p != front);

    return 0;
}
