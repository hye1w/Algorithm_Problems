#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    int num_list[100]; 

    int num = 0;
    int num_count = 0;

    while (num_count < x) {
        num++;
        num_count += num;
    }

    num_count -= num;

    int i, j;
    if (num % 2 == 0) {
        i = x - num_count;
        j = num - i + 1;
    } else {
        i = num - (x - num_count) + 1;
        j = x - num_count;
    }

    printf("%d/%d\n", i, j);

    return 0;
}
