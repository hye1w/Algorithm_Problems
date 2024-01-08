#include <stdio.h>

int main()
{
	int num1, num2;
	scanf("%d", &num1);
	scanf("%d", &num2);
    
	int num3 = num1 * (num2 % 10);                         
	printf("%d\n", num3);
    
	int num4 = num1 * ((num2 / 10) % 10);
    printf("%d\n", num4);
	
    int num5 = num1 * (num2 / 100);
    printf("%d\n", num5);
	
    int result = num3 + num4 * 10 + num5 * 100;
	printf("%d\n", result);

    return 0;
}
