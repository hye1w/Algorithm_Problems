#include <stdio.h>

void isPerfect(int n) {
    int sum = 0;
    int factors[100000]; 
    
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            factors[index++] = i;
            sum += i;
        }
    }

    if (sum == n) {
        printf("%d = ", n);
        for (int i = 0; i < index; i++) {
            printf("%d", factors[i]);
            if (i != index - 1) {
                printf(" + ");
            }
        }
        printf("\n");
    } else {
        printf("%d is NOT perfect.\n", n);
    }
}

int main() {
    int num;

    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        isPerfect(num);
    }

    return 0;
}
