#include <stdio.h>

int main() {
    int T; 
    scanf("%d", &T);

    while (T--) {
        int C;  
        scanf("%d", &C);
 
        int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
 
        quarters = C / 25;
        C %= 25;

        dimes = C / 10;
        C %= 10;

        nickels = C / 5;
        C %= 5;

        pennies = C;
 
        printf("%d %d %d %d\n", quarters, dimes, nickels, pennies);
    }

    return 0;
}
