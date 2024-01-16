#include <stdio.h>

int main(void)
{
	int a[1000] = {0}, b[1000] = {0};
    
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[x]++;
		b[y]++;
	}
	for (int i = 0; i < 1000; i++)
		if (a[i] == 1) printf("%d ", i);
    
	for (int i = 0; i < 1000; i++)
		if (b[i] == 1) printf("%d", i);
  
  return 0;
}
