#include <stdio.h>
#include <string.h>

int main() {
    char N[20]; 
    fgets(N, sizeof(N), stdin);
    N[strlen(N) - 1] = '\0'; 

    long long digit = 0;

    for (int i = 1; i < strlen(N); i++) {
        digit += i * 9 * ((long long)pow(10, i - 1));
    }

    digit += strlen(N) * (atoll(N) - ((long long)pow(10, strlen(N) - 1)) + 1);

    printf("%lld\n", digit);

    return 0;
}
