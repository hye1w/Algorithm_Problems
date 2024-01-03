#include<stdio.h>

int main() {
    int num;
    int number[1000];
    int change = 0;
    scanf("%d", &num);
    
    for(int i=0; i<num; i++) {
        scanf("%d", &number[i]);
    }
    
    for(int i=0; i<num-1; i++) {
        for(int i=0; i<num-1; i++) {
            if(number[i+1] < number[i]) {
                change = number[i];
                number[i] = number[i+1];
                number[i+1] = change;
            }
        }
    }
    
    for(int i=0; i<num; i++) {
        printf("%d\n", number[i]);
    }
    
    return 0 ;
}
