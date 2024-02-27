#include <stdio.h>

int main() {
    long long X, Y;
    scanf("%lld %lld", &X, &Y);

    long long low = 0, high = 1000000000;
    long long needed_games = -1;
 
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long new_X = X + mid;
        long long new_Y = Y + mid;
        long long win_rate = (new_Y * 100) / new_X;
 
        if (win_rate > Y * 100 / X) {
            needed_games = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%lld\n", needed_games);

    return 0;
}
