#include <stdio.h>

int main() {
    int N, kim, im;
    scanf("%d %d %d", &N, &kim, &im);

    int round = 1;

    while (1) { 
        if ((kim + 1) / 2 == (im + 1) / 2) {
            printf("%d\n", round);
            break;
        }
 
        kim = (kim + 1) / 2;
        im = (im + 1) / 2;
        round++;
 
        if (N % 2 == 1 && N / 2 == 1)
            N = N / 2 + 1;
        else
            N = N / 2;
    }

    return 0;
}
