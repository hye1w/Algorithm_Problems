#include <stdio.h>

int main(void)
{
    int n, m;
    int min = 50;
    
    scanf("%d %d", &n, &m);
    char arr[n][m];
    
    for(int i = 0; i < n; i++)
        scanf("%s", arr[i]);
    
    for(int i = 0; i <= n-8; i++)
    {
        for(int j = 0; j <= m-8; j++)
        {
            int B_odd = 0;
            int B_even = 0;
            
            for(int a = i; a < i+8; a++)
            {
                for(int b = j; b < j+8; b++)
                {
                    if((a+b) % 2 == 0)
                    {
                        if(arr[a][b] == 'B')
                            B_odd++;
                        else
                            B_even++;
                    }
                    else
                    {
                        if(arr[a][b] == 'B')
                            B_even++;
                        else
                            B_odd++;
                    }
                }
            }
        if(B_odd < min)
            min = B_odd;
        if(B_even < min)
            min = B_even;
        }
    }
    printf("%d", min);
    return 0;
}
