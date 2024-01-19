#include <stdio.h>

int N, M;
int arr[8];                                        
int check[9];                                       

void backtracking(int);

int main() {
   scanf("%d %d", &N, &M);
   backtracking(0);
}

void backtracking(int cnt) {
   if (cnt == M) {                                  // 배열 길이가 M이라면
      for (int i = 0; i < cnt; i++)
         printf("%d ", arr[i]);
      printf("\n");
   }
   else {
      for (int i = 1; i <= N; i++) {            
         if (check[i] == 0) {                     
            check[i] = 1;                        
            arr[cnt] = i;                       
            backtracking(cnt + 1);                  
            check[i] = 0;                        
         }
      }
   }
} 
