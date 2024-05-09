#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char st[1000];
    scanf("%s", st);

    char answer[2000] = "";
    int count = 0;
    int flag = 0;

    for (int i = 0; i < strlen(st); i++) {
        if (st[i] == 'X') {
            count += 1;
        } else {
            if (count > 0) {
                if (count % 4 != 0 && count % 2 != 0) {
                    printf("-1\n");
                    exit(0);
                }
                if (count / 4 > 0) {
                    for (int j = 0; j < count / 4; j++) {
                        strcat(answer, "AAAA");
                    }
                    count = count % 4;
                }
                if (count / 2 > 0) {
                    for (int j = 0; j < count / 2; j++) {
                        strcat(answer, "BB");
                    }
                    count = count % 2;
                }
                count = 0;
            }
            strcat(answer, ".");
        }
    }

    if (count > 0 && !flag) {
        if (count % 4 != 0 && count % 2 != 0) {
            printf("-1\n");
            exit(0);
        }
        if (count / 4 > 0) {
            for (int j = 0; j < count / 4; j++) {
                strcat(answer, "AAAA");
            }
            count = count % 4;
        }
        if (count / 2 > 0) {
            for (int j = 0; j < count / 2; j++) {
                strcat(answer, "BB");
            }
            count = count % 2;
        }
        count = 0;
    }

    printf("%s\n", answer);
    
    return 0;
}
