#include <stdio.h>

int main(void)
{
  int m, n, i, j, k;
  int l, arr[102]={0};
  scanf("%d %d", &n, &m);
  
  for (l=0; l<m; l++)
    {
      scanf("%d %d %d", &i, &j, &k);
      for (; i<=j; i++)
        {
          arr[i] = k;
        }
    }
  for (l=1; l<=n; l++)
    {
      printf("%d ", arr[l]);
    }
} 
