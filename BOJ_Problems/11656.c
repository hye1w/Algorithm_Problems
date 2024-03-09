#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char S[1001];
    scanf("%s", S);

    int len = strlen(S);
    
    char *suffix[len];

    for (int i = 0; i < len; i++) {
        suffix[i] = &S[i];
    }
 
    qsort(suffix, len, sizeof(char*), compare);

    for (int i = 0; i < len; i++) {
        printf("%s\n", suffix[i]);
    }

    return 0;
}
