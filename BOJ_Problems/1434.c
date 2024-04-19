#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int waste = 0;
    int box_list[N];
    int book_list[M];

    for (int i = 0; i < N; i++) {
        scanf("%d", &box_list[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &book_list[i]);
    }

    while (M != 0) {
        if (box_list[0] >= book_list[0]) {
            box_list[0] -= book_list[0];
            for (int i = 0; i < M - 1; i++) {
                book_list[i] = book_list[i + 1];
            }
            M--;
        } else {
            waste += box_list[0];
            for (int i = 0; i < N - 1; i++) {
                box_list[i] = box_list[i + 1];
            }
            N--;
        }
    }

    for (int i = 0; i < N; i++) {
        waste += box_list[i];
    }

    printf("%d\n", waste);

    return 0;
}
