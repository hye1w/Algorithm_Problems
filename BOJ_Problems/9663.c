#include <stdio.h>

#define MAX_N 14

int N;
int answer = 0;
int col[MAX_N]; 

int abs(int a) {
    return (a < 0) ? -a : a;
}

int safe(int row, int colNum) {
    for (int i = 0; i < row; i++) {
        if (col[i] == colNum || abs(i - row) == abs(col[i] - colNum)) {
            return 0;
        }
    }
    return 1;
}

void solve(int row) {
    if (row == N) {
        answer++;
        return;
    }

    for (int colNum = 0; colNum < N; colNum++) {
        if (safe(row, colNum)) {
            col[row] = colNum;
            solve(row + 1);
        }
    }
}

int main() {
    scanf("%d", &N);

    solve(0);

    printf("%d\n", answer);

    return 0;
}
