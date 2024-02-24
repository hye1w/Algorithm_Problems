#include <stdio.h>
#include <string.h>

int matchPattern(const char *pattern, const char *filename) {
    while (*pattern != '\0' && *filename != '\0') {
        if (*pattern == '*') {
            while (*(pattern + 1) == '*')
                pattern++;
            
            while (*filename != '\0') {
                if (matchPattern(pattern + 1, filename))
                    return 1;
                filename++;
            }
            return matchPattern(pattern + 1, filename); 
        } else if (*pattern == *filename || *pattern == '?') {
            pattern++;
            filename++;
        } else {
            return 0;
        }
    }
    return *pattern == '\0' && *filename == '\0';
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 

    char pattern[101];
    scanf("%s", pattern);

    for (int i = 0; i < N; i++) {
        char filename[101];
        scanf("%s", filename);

        if (matchPattern(pattern, filename))
            printf("DA\n");
        else
            printf("NE\n");
    }

    return 0;
}
