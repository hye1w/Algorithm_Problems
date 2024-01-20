#include <stdio.h>

void backtracking(int num, int last);
int n, m;
int arr[8];

int main() {
   scanf("%d %d", &n, &m);
   backtracking(0, 0);
   return 0;
}

void backtracking(int num, int last) {
   int i;
   if (num == m) {
      for (i = 0; i < m; i++)
         printf("%d ", arr[i] + 1);
      printf("\n");
   }
   else {
      for (i = last; i < n; i++) {
         arr[num] = i;
         backtracking(num + 1, i + 1);
      }
   }
}
