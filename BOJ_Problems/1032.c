#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char filenames[N][51];
    for (int i = 0; i < N; i++) {
        scanf("%s", filenames[i]);
    }

    int filename_length = strlen(filenames[0]);
    char pattern[51];

    for (int i = 0; i < filename_length; i++) {
        char current_char = filenames[0][i];
        int j;

        for (j = 1; j < N; j++) {
            if (filenames[j][i] != current_char && filenames[j][i] != '?')
                break;
        }

        if (j == N)
            pattern[i] = current_char;
        else
            pattern[i] = '?';
    }

    pattern[filename_length] = '\0';
    printf("%s\n", pattern);

    return 0;
}
