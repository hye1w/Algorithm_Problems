#include <stdio.h>
#include <string.h>

int main() {
    char word[101];
    int length; 
    
    scanf("%s", word);

    length = strlen(word);

    printf("%d", length);

    return 0;
}
