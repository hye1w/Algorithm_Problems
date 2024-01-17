#include <stdio.h>

int main()
{
    int n, k, human[5001], sit = 0;
    
    scanf("%d", &n);
    scanf("%d", &k);
    
    printf("<");
    
    for(int i=1; i<=n; i++)
    {
        human[i] = 0;
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            sit++;
            if(sit > n)
                sit = 1;
            while(1)
            {
                if(human[sit] == 1)
                    sit++;
                else if(sit > n)
                    sit = 1;
                else
                    break;
            }
        }
        printf("%d", sit);
        if(i != n)
            printf(", ");
        human[sit] = 1;
    }
    printf(">");
    return 0;
}
