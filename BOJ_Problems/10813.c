#include <stdio.h>

int a[101]={0,};

void swap(int x, int y)
{
	int temp;

	temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int main()
 {
	int n, m, i, j,k;

	scanf("%d %d", &n,& m);

	for (k = 1; k <= n; k++)
		a[k] = k;

	for (k = 1; k <= m; k++)
	{
		scanf("%d %d", &i, &j);
		swap(i , j );
	}

	for (k = 1; k <= n; k++)
		printf("%d ", a[k]);

	return 0;
}
