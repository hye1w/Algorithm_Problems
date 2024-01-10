#include<stdio.h>

int main(void)
{
    int student[31] = {0};
    int i, number;
    
    for(i = 0; i < 28; i++)
    {
        scanf("%d", &number);
        
        student[number] = 1;
    }
    
    for(i = 1; i <= 30; i++)
    {
        if(student[i] == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
