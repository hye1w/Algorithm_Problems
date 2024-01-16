#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    if(a == b && b == c && a == 60)
        printf("Equilateral");
    else if(a + b + c == 180)
    {
        if(a == b || a == c || b == c)
            printf("Isosceles");
        else if(a != b && b != c && a != c)
            printf("Scalene");
    }
    else if(a + b + c != 180)
        printf("Error");
    
    return 0;
}
