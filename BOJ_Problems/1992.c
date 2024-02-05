#include <stdio.h>

#define MAX_N 64

void compressQuadTree(int N, char image[MAX_N][MAX_N], int row, int col) {
    char currentPixel = image[row][col];
    int half = N / 2;

    if (N == 1) {
        printf("%c", currentPixel);
        return;
    }

    int sameColor = 1;
    for (int i = row; i < row + N; i++) {
        for (int j = col; j < col + N; j++) {
            if (image[i][j] != currentPixel) {
                sameColor = 0;
                break;
            }
        }
        if (!sameColor) {
            break;
        }
    }

    if (sameColor) {
        printf("%c", currentPixel);
    } else {
        printf("(");
        compressQuadTree(half, image, row, col);
        compressQuadTree(half, image, row, col + half);
        compressQuadTree(half, image, row + half, col);
        compressQuadTree(half, image, row + half, col + half);
        printf(")");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    char image[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%s", image[i]);
    }

    compressQuadTree(N, image, 0, 0);

    return 0;
}
