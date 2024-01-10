#include <stdio.h>

int main(void)
{
    int n, v, i;
    int ary[100];
    int count = 0;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &ary[i]);
    }
    scanf("%d", &v);
    
    for(i = 0; i < n; i++)
    {
        if(ary[i] == v)
        {
            count++;
        }
    }
    
    printf("%d", count);
    
    return 0;
}
