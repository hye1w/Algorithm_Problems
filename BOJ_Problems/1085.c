#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    if (x > w / 2) x = w - x;
    if (y > h / 2) y = h - y;
    
    (x < y) ? printf("%d", x) : printf("%d", y);
} 
