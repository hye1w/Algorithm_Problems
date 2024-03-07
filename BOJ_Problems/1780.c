#include <stdio.h>

int paper[2187][2187];
int count[3] = {0};  

int isSame(int row_start, int row_end, int col_start, int col_end) {
    int first = paper[row_start][col_start];
    for (int i = row_start; i <= row_end; i++) {
        for (int j = col_start; j <= col_end; j++) {
            if (paper[i][j] != first)
                return 0; 
        }
    }
    return 1; 
}
 
void cut(int row_start, int row_end, int col_start, int col_end) {
    if (isSame(row_start, row_end, col_start, col_end)) { 
        count[paper[row_start][col_start] + 1]++;
    } else { 
        int row_size = (row_end - row_start + 1) / 3;
        int col_size = (col_end - col_start + 1) / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cut(row_start + i * row_size, row_start + (i + 1) * row_size - 1,
                         col_start + j * col_size, col_start + (j + 1) * col_size - 1);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }
    cut(0, N - 1, 0, N - 1);

    printf("%d\n%d\n%d\n", count[0], count[1], count[2]);

    return 0;
}
