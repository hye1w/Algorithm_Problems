#include <stdio.h>
#include <string.h>

int main() {
    char word[101];
    int positions[26]; 
    
    memset(positions, -1, sizeof(positions));
     
    scanf("%s", word);
     
    for (int i = 0; word[i] != '\0'; i++) { 
        int index = word[i] - 'a'; 
        if (positions[index] == -1) {
            positions[index] = i;
        }
    }
     
    for (int i = 0; i < 26; i++) {
        printf("%d ", positions[i]);
    }
    
    return 0;
}
