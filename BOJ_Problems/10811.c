#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main() 
{
	int n, m, x, y;
	scanf("%d %d", &n, &m);

	int *num = malloc(sizeof(int) * n);  

	for (int i = 0; i < n; i++) {
		num[i] = i+1;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		for (int j = x-1; j <= (x+y-2)/2; j++) {
			int temp = num[j];     
			num[j] = num[x + y - j-2];  
			num[x + y - j-2] = temp;  
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
	free(num);	
    
	return 0;
}
