#include <stdio.h>

int main(void)
{
	int n, m, max=0;
	int value, array[100];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	for (int a = 0; a < n; a++)
	{
		for (int b = 1; b < n; b++)
		{
			if (b != a)
			{
				for (int c = 2; c < n; c++)
				{
					if ((b != c) && (a != c))
					{
						value = array[a] + array[b] + array[c];
						if ((value <= m)&&(value >= max))
							max = value;
					}
				}
			}
		}
	}
	printf("%d", max);
	return 0;
} 
