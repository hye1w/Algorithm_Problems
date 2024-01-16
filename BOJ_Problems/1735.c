#include <stdio.h>

int gcd(int x, int y) {
	int temp;
	if (x < y) 
    {
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
	int N[2] = { 0, };  
	int D[2] = { 0, }; 
	int num, deno, temp;
	for (int i=0; i<2; i++) {
		scanf("%d %d", &N[i], &D[i]);
	}
	num = (N[0] * D[1]) + N[1] * D[0];
	deno = D[0] * D[1];
	temp = gcd(num, deno);
	printf("%d %d", num / temp, deno / temp);
    
	return 0;
}
