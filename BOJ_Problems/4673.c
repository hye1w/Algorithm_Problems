#include <stdio.h>
#include <stdbool.h>

#define MAX_NUMBER 10000

int next(int n) {
    int sum = n;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    bool self_numbers[MAX_NUMBER + 1] = {false}; 

    for (int i = 1; i <= MAX_NUMBER; i++) {
        int next_number = next(i);  
        if (next_number <= MAX_NUMBER) {
            self_numbers[next_number] = true;  
        }
    }

    for (int i = 1; i <= MAX_NUMBER; i++) {
        if (!self_numbers[i]) { 
            printf("%d\n", i);
        }
    }

    return 0;
}
