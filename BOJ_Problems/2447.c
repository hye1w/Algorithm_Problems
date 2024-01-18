#include <stdio.h>

int star(int a, int b, int n)
{
	if ((a / n) % 3 == 1 && (b / n) % 3 == 1)
	{
		printf(" ");
	}
	else
	{
		if (n / 3 == 0) 
			printf("*");
		else
		{
			star(a, b, n / 3);  
		}
	}
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
    
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			star(i, j, n);
			j++;
		}
		printf("\n");
		i++;
	}
}
