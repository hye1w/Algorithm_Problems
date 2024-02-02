#include <stdio.h> 

int arr[200], students[200];
int N;
int max=0;

int main() {
	scanf("%d", &N);
    
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
    
	for (int i=0; i<N; i++) {
		students[i]=1;
        
		for (int j=0; j<i; j++) {
			if(arr[j] < arr[i] && students[i] < students[j]+1) {
				students[i] = students[j]+1;
			}
		}
	}
    
	for (int i=0; i<N; i++) {
		if (max < students[i]) {
			max = students[i];
		}
	}
    
	printf("%d", N-max);
}
