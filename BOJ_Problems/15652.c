#include <stdio.h>

int arr[100];

void backtracking (int j, int n, int m, int i)
{
    if (j == m)
    {
        for (int a = 0; a < m; a++)
            printf("%d ", arr[a]);
        printf("\n");
    }
    else
    {
        for (; i <= n; i++)
        {
            arr[j] = i;
            backtracking(j + 1, n, m, i);
        }
    }
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    backtracking(0, n, m, 1);
    return (0);
}
