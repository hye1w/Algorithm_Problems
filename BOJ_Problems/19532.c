#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f;
    int x, y;
    
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    
    for(int x = -999; x < 1000; x++)
        for(int y = -999; y < 1000; y++)
            if((a * x + b * y == c) && (d * x + e * y == f))
            {
                printf("%d %d", x, y);
                break;
            }
}
