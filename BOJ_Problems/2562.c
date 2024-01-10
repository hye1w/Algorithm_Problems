#include<stdio.h>

int main(void)
{
    int ary[10];
    int i, max = 0, index = 0;
    
    for(i = 0; i < 9; i++)
    {
        scanf("%d", &ary[i]);
    }
    
    for(i = 0; i < 9; i++)
    {
        if(ary[i] > max)
        {
            max = ary[i];
            index = i;
        }
    }
    
    printf("%d\n", max);
    printf("%d\n", index+1);
    
    return 0;
}
