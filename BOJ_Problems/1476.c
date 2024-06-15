#include <stdio.h>

int main() {
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);

    int eMax = 15;
    int sMax = 28;
    int mMax = 19;

    int year = 1;

    while ((year - 1) % eMax + 1 != E || (year - 1) % sMax + 1 != S || (year - 1) % mMax + 1 != M) {
        year++;
    }

    printf("%d\n", year);
    return 0;
}
