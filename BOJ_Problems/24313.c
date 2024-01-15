#include<stdio.h>

double a1,a0,c,n0;

int main(){
    scanf("%lf %lf %lf %lf", &a1, &a0, &c, &n0);
    if(c>a1) 
        printf("%d", n0 >= a0/(c-a1));
    else if(c < a1) 
        printf("0");
    else 
        printf("%d", a0 <= 0);
} 
