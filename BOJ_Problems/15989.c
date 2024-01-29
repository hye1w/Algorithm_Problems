#include <stdio.h>

int main()
{
    int array[10001][4] = {0};
        
    array[1][1] = 1;
    array[2][1] = 1;
    array[3][1] = 1;
    array[2][2] = 1;
    array[3][2] = 1;
    array[3][3] = 1;
    
    int T;
    scanf("%d", &T);
    
    for(int a = 0; a < T; a++){
        int n;
        scanf("%d", &n);
        
        for(int i = 4; i <= n; i++){
            array[i][1] = array[i-1][1];
            array[i][2] = array[i-2][2] + array[i-2][1];
            array[i][3] = array[i-3][3] + array[i-3][2] + array[i-3][1];
        }
        
        printf("%d\n", array[n][1] + array[n][2] + array[n][3]);
    } 
    return 0;
}
