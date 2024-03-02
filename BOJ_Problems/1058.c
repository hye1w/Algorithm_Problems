#include <stdio.h>

#define MAX_N 50

int main() {
    int N;
    char friendship[MAX_N][MAX_N];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", friendship[i]);
    }

    int max_friends = 0;
    for (int i = 0; i < N; i++) {
        int count_friends = 0; 
        for (int j = 0; j < N; j++) {
            if (i == j) continue; 
            if (friendship[i][j] == 'Y') {
                count_friends++;
            } else {
                for (int k = 0; k < N; k++) {
                    if (friendship[i][k] == 'Y' && friendship[j][k] == 'Y') {
                        count_friends++;
                        break;
                    }
                }
            }
        }
        if (count_friends > max_friends) {
            max_friends = count_friends; 
        }
    }
    printf("%d\n", max_friends);

    return 0;
}
