#include <stdio.h>

int main() {
    char S[1000001];
    scanf("%s", S);

    int cnt = 0;
    char v = S[0];
    for (int i = 1; S[i] != '\0'; ++i) {
        if (S[i] != v) {
            cnt++;
        }
        v = S[i];
    }

    int result = (cnt + 1) / 2;
    printf("%d\n", result);

    return 0;
}
