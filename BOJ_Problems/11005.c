#include <stdio.h>
#include <stdlib.h>
 
void convert(int num, int base) { 
    char result[32];
    int index = 0;
 
    while (num > 0) {
        int remainder = num % base;
        if (remainder < 10) { 
            result[index++] = remainder + '0';
        } else { 
            result[index++] = remainder - 10 + 'A';
        }
        num /= base;
    }
 
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    int N, B;
    
    scanf("%d %d", &N, &B);
 
    convert(N, B);

    return 0;
}
