#include<stdio.h>
#include<string.h>

int main() {
	char expression[51];
	scanf("%s", expression);
	int len = strlen(expression);

	int num = 0;
    int result = 0;
    int temp;	 
	int sign = 0;	 
    
	for (int i = 0; i < len; i++) {
		temp = 0;
		if ((int)expression[i] >= 48) {
			temp = ((int)expression[i] - 48);
			num = num * 10 + temp;
		}
		else if (expression[i] == '-' && sign == 0) {
			result += num;
			sign = 1;
			num = 0;
		}
	
		else if (sign == 0) {	
			result += num;
			num = 0;
		}
		
		else {	
			result -= num;
			num = 0;
		}
	}

	if (sign == 1) {	
		result -= num;
	}
	else result += num;	

	printf("%d", result);

	return 0;
}
