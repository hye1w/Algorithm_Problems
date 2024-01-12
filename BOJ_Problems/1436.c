#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int N, i, test, count = 0;
    scanf("%d", &N);
    
    for(i = 666;; i++)
    {
        test = i;
        while(test >= 666)
        {
            if(test % 1000 == 666)
            {
                count++;
                break;
            }
            test = test / 10;
        }
        if(count == N)
            break;
    }
    printf("%d", i);
    
    return 0;
}
