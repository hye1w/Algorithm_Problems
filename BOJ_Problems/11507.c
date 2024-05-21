#include <stdio.h>
#include <string.h>

int main() {
    char S[1001];
    scanf("%s", S);
    
    int len = strlen(S);
    int cards[4][14] = {0};   
    int pCount = 0, kCount = 0, hCount = 0, tCount = 0;
    
    for (int i = 0; i < len; i += 3) {
        char suit = S[i];
        int number = (S[i + 1] - '0') * 10 + (S[i + 2] - '0');
        
        int suitIndex;
        if (suit == 'P') suitIndex = 0;
        else if (suit == 'K') suitIndex = 1;
        else if (suit == 'H') suitIndex = 2;
        else if (suit == 'T') suitIndex = 3;
        
        if (cards[suitIndex][number] == 1) {
            printf("GRESKA\n");
            return 0;
        }
        
        cards[suitIndex][number] = 1;
    }
    
    for (int i = 1; i <= 13; i++) {
        if (cards[0][i] == 0) pCount++;
        if (cards[1][i] == 0) kCount++;
        if (cards[2][i] == 0) hCount++;
        if (cards[3][i] == 0) tCount++;
    }
    
    printf("%d %d %d %d\n", pCount, kCount, hCount, tCount);
    return 0;
}
