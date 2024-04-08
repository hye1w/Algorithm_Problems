#include <stdio.h>
#include <stdlib.h>

int main() {
    int inputNum;
    
    scanf("%d", &inputNum);

    int count = 1;
    int start = 2;
    int end = 7;

    while (1) {
        if (inputNum == 1) {
            printf("%d\n", count);
            break;
        }

        if (inputNum >= start && inputNum <= end) {
            printf("%d\n", count + 1);
            break;
        }

        count++;

        start = end + 1;
        end = end + 6 * count;
    }

    return 0;
}
