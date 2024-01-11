#include <stdio.h>
#include <string.h>

int main()
{
	
	char words[101];  
	int N ; 
	scanf("%d", &N);
	
	int cnt = N; 
	
	for (int i = 0; i < N; i++)                       
	{
		char first = '0';                             
		int Alphabet[26] = {0};
		scanf("%s", words);
		for (int j = 0; words[j] != '\0'; j++) 
		{
			
			if (first != words[j])             
			{
				first = words[j];
				Alphabet[words[j]-'a'] += 1;
			}

			if (Alphabet[words[j] - 'a'] == 2)      
			{
				cnt -= 1;
				break;
			}
		}
	}
	printf("%d", cnt);
    
	return 0;
} 
