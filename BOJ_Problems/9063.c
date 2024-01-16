#include <stdio.h>

int main() {
    int a[100001], b[100001];
    int n;
    int max_x = -10000, max_y = -10000;
    int min_x = 10000, min_y = 10000;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d",&a[i], &b[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        if(max_x < a[i])
            max_x = a[i];
        if(max_y < b[i])
            max_y = b[i];
        if(min_x > a[i])
            min_x = a[i];
        if(min_y > b[i])
            min_y = b[i];
    }
    printf("%d\n",(max_x - min_x) * (max_y - min_y));
    
    return 0;
} 
