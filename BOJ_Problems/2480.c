#include <stdio.h>

int main() {
    int dice[3];
    int count[7] = {0};  
 
    for (int i = 0; i < 3; i++) {
        scanf("%d", &dice[i]);
        count[dice[i]]++;
    }

    int reward = 0;
 
    for (int i = 1; i <= 6; i++) {
        if (count[i] == 3) {
            reward = 10000 + i * 1000;
            printf("%d\n", reward);
            return 0;
        }
    }
 
    for (int i = 1; i <= 6; i++) {
        if (count[i] == 2) {
            reward = 1000 + i * 100;
            printf("%d\n", reward);
            return 0;
        }
    }
 
    int max_dice = 0;
    for (int i = 0; i < 3; i++) {
        if (dice[i] > max_dice)
            max_dice = dice[i];
    }
    reward = max_dice * 100;
    printf("%d\n", reward);

    return 0;
}
