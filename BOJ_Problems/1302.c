#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    int n;
    char input[MAX_LENGTH];
    char most_frequent[MAX_LENGTH] = "";
    int max_count = -1;

    scanf("%d", &n);

    typedef struct {
        char key[MAX_LENGTH];
        int count;
    } KeyValue;

    KeyValue *table = (KeyValue *)malloc(n * sizeof(KeyValue));

    for (int i = 0; i < n; ++i) {
        scanf("%s", input);

        int found = 0;
        for (int j = 0; j < i; ++j) {
            if (strcmp(table[j].key, input) == 0) {
                table[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(table[i].key, input);
            table[i].count = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (table[i].count > max_count || (table[i].count == max_count && strcmp(table[i].key, most_frequent) < 0)) {
            max_count = table[i].count;
            strcpy(most_frequent, table[i].key);
        }
    }

    printf(most_frequent);

    free(table);

    return 0;
}
