#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b)
{
  int A = *(int*)a;
  int B = *(int*)b;
    
  if(A>B) return 1;
  else if(A<B) return -1;
  else return 0;
}

int main(void)
{
    int N;
    int arr[1000001];
    scanf("%d",&N);

    for(int i=0 ; i<N ; i++)
    {
      scanf("%d",&arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);
    
    for(int i=0 ; i<N ; i++)
    {
      printf("%d\n", arr[i]);
    }
    return 0;
}
