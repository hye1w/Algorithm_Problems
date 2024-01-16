#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
	int temp;
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
	while (y != 0)
	{
		temp = x;
		x = y;
		y = temp % y;
	}
	return x;
}

int main() {
	int N, temp, plus_locate, count = 1;
	scanf("%d", &N);
	int* locate = malloc(sizeof(int) * N); 
	int* min = malloc(sizeof(int) * N - 1); 
    
	for (int i = 0; i < N; i++) 
        scanf("%d", &locate[i]); 
	for (int i = 0; i < N - 1; i++) 
        min[i] = locate[i + 1] - locate[i]; 
	temp = min[0]; 
	for (int i = 1; i < N-1; i++) 
        temp = gcd(temp, min[i]); 

	plus_locate = locate[0];
	while (plus_locate!=locate[N-1]) 
	{
		plus_locate += temp; 
		count++; 
	}
	printf("%d", count - N);
	return 0;
}
