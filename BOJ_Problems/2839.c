#include<stdio.h>

int main(void)
{
	int sugar3 = 0; 
	int sugar5 = 0;  
	int N;
    
	scanf("%d", &N);
    
	while (N > 0)  
	{
		if (N % 5 == 0)  
		{
			N -= 5;  
			sugar5++;  
		}
		else
		{
			N -= 3;
			sugar3++; 
		}
	}

	if (N == 0) printf("%d", sugar5 + sugar3);
	else printf("%d", -1);
    
	return 0;
} 
