#include <stdio.h>
#include <string.h>

int main() {
    char L[100], R[100];
    scanf("%s %s", L, R);

    if (strlen(L) != strlen(R)) {
        printf("0\n");
    } else {
        int count = 0;
        for (int i = 0; i < strlen(L); i++) {
            if (L[i] == R[i] && L[i] == '8') {
                count++;
            } else {
                if (L[i] != R[i]) {
                    break;
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
