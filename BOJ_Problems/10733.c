#include <stdio.h>
#include <stdlib.h>

void push(int arr[], int *top, int n)
{
    (*top)++;
    arr[*top] = n;
}

void pop(int *top)
{
    (*top)--;
}

int main()
{
    int n, tmp;
    int top = -1;
    int *arr;
    
    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &tmp);
        if(tmp == 0)
        {
            pop(&top);
        }
        else 
            push(arr, &top, tmp);
    }
    
    int sum = 0;
    for(int i=0; i <= top; i++)
    {
        sum += arr[i];  
    }
    printf("%d", sum);
    return 0;
}
