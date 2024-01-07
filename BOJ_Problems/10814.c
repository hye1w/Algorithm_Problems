#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
   int age;
   char name[101];
}member;

int compare(const void* a, const void* b)
{
   member* aa = (member*)a;
   member* bb = (member*)b;
   if (aa->age <= bb->age)
      return -1;
   else
      return 1;
}

int main(void)
{
   int N;
   scanf("%d", &N);
   member* arr = (member*)malloc(sizeof(member) * N);

   for (int i = 0; i < N; i++)
   {
      scanf("%d %s", &arr[i].age, arr[i].name);
   }

   qsort(arr, N, sizeof(member), compare);

   for (int i = 0; i < N; i++)
   {
      printf("%d %s\n", arr[i].age, arr[i].name);
   }

   free(arr);

   return 0;
}
