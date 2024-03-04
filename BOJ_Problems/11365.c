#include <stdio.h>
#include <string.h>

int main() {
    char password[501];  
    char reversed[501];  

    while (1) {
        fgets(password, sizeof(password), stdin);

        if (strcmp(password, "END\n") == 0)
            break;

        int len = strlen(password); 
        for (int i = 0; i < len - 1; i++) { 
            reversed[i] = password[len - 2 - i]; 
        }

        reversed[len - 1] = '\0'; 
        printf("%s\n", reversed);  
    }
    return 0;
}
