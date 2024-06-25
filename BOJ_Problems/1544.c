#include <stdio.h>
#include <string.h>

#define MAX_N 50
#define MAX_LEN 50
 
char words[MAX_N][MAX_LEN + 1];
 
int isCyclicEqual(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    if (lenA != lenB) return 0;
     
    char temp[MAX_LEN * 2 + 1];
    strcpy(temp, b);
    strcat(temp, b);
     
    return strstr(temp, a) != NULL;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    int uniqueCount = 0;
    int isUnique[MAX_N] = {0};

    for (int i = 0; i < N; i++) {
        if (isUnique[i]) continue;  
        
        uniqueCount++;
        
        for (int j = i + 1; j < N; j++) {
            if (isCyclicEqual(words[i], words[j])) {
                isUnique[j] = 1;  
            }
        }
    }

    printf("%d\n", uniqueCount);
    
    return 0;
}
