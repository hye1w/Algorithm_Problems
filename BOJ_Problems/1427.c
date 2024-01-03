#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[10];
    int count=0;
    
    for(int i=0; n>0; i++) 
    {
        arr[i] =  n % 10;
        n /= 10;
        count++;
    }
    
    for(int i=count-1; i>=0; i--)
    {
        for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < count; i++)		 
	{
		printf("%d", arr[i]);
	}
}
