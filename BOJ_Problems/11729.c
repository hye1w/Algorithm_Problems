#include <stdio.h>
#include <math.h>

void hanoi(int ring, int start, int end, int mid);

int main() 
{
    int n;
    int num;
    scanf("%d", &n);
    num = pow(2,n)-1;
    printf("%d\n", num);
    hanoi(n,1,3,2);
    return 0;
}

void hanoi(int ring, int start, int end, int mid)
{
    if(ring == 1)
    {
        printf("%d %d\n", start, end);
        return;
    }
    hanoi(ring-1, start, mid, end);
    printf("%d %d\n", start, end);
    hanoi(ring-1, mid, end, start);
}
