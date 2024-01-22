#include <stdio.h>

int N;
int numbers[11];
int operators[4];

int max = -1000000000; 
int min = 1000000000; 

int calculate(int a, int b, int op) {
    if (op == 0) return a + b;
    else if (op == 1) return a - b;
    else if (op == 2) return a * b;
    else return a / b;
}

void cases(int depth, int result) {
    if (depth == N) { 
        if (result > max) max = result;
        if (result < min) min = result;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i]--;
            cases(depth + 1, calculate(result, numbers[depth], i));
            operators[i]++;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &numbers[i]);
    for (int i = 0; i < 4; i++)
        scanf("%d", &operators[i]);

    cases(1, numbers[0]);
    printf("%d\n%d", max, min);
    return 0;
}
