#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, m;
int arr[7];
void backtracking(int cnt);

int main() {
   scanf("%d %d", &n, &m);
   backtracking(0);
   return 0;
}

void backtracking(int cnt) {
   int i;
   if (cnt == m) {
      for (i = 0; i < m; i++)
         printf("%d ", arr[i]);
      printf("\n");
   }
   else {
      for (i = 1; i <= n; i++) {
         arr[cnt] = i;
         backtracking(cnt + 1);
      }
   }
}
