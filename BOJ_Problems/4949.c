#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 102

char stack[MAX];

int main() 
{
    int top = -1, i;
    char arr[MAX];
    
    fgets(arr, MAX, stdin);
    while(strcmp(arr, ".\n"))
    {
        for(i=0; i<strlen(arr); i++)
        {
            if(arr[i] == '(')
                stack[++top] = arr[i];
            else if(arr[i] == ')')
            {
                if(stack[top--] != '(')
                    break;
            }
            else if(arr[i] == '[')
                stack[++top] = arr[i];
            else if(arr[i] == ']')
            {
                if(stack[top--] != '[')
                    break;
            }
        }
        if(i != strlen(arr) || top != -1)
            printf("no\n");
        else
            printf("yes\n");
        top = -1;
        fgets(arr, MAX, stdin);
    }
    return 0;
}
