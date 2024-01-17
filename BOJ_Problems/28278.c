#include <stdio.h>

int stack[1000000], cnt = 0;

int main() 
{
    int N, order, num;
    scanf("%d", &N);
    
    for(int i=0; i < N; i++) 
    {
        scanf("%d", &order);
        switch(order)
        {
            case 1:
                scanf("%d", &num);
                stack[cnt] = num;
                cnt++;
                break;
            case 2:
                if(cnt == 0) 
                    printf("-1\n"); 
                else 
                {
                    printf("%d\n", stack[cnt-1]);
                    cnt--;
                }
                break;
            case 3:
                printf("%d\n", cnt);
                break;
            case 4:
                if(cnt == 0)
                    printf("1\n");
                else 
                    printf("0\n");
                break;
            case 5:
                if(cnt == 0)
                    printf("-1\n");
                else 
                    printf("%d\n", stack[cnt-1]);
                break;
            default:
                printf("wrong order\n");
         }  
    }   
}
