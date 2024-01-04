#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    double k = (double)a/(double)b;
    printf("%.9lf", k); 
}
