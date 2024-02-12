#include<stdio.h>

#define MAX_N 1000

int main(void){
	
	int N, num;
  int queue[MAX_N];
	scanf("%d", &N);
	num = N;
	
	for(int i=0; i<N; i++){
		queue[i] = i+1;
	}
	
	while(num>=1){
		printf("%d ", queue[0]);
		num--;
    
		int t = queue[1];
		for(int i=2; i<=num; i++){
			queue[i-2] = queue[i];
		}
		queue[num-1] = t;	
	}
	return 0;
}
