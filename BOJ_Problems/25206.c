#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    double sum = 0;
    double totalunit = 0;
    
    for(int i = 0; i < 20; i++)
    {
        char subject[51], grade[3];
        double unit, score;
        
        scanf("%s %lf %s", subject, &unit, grade);
        if(grade[0] == 'P') continue;
        else if(grade[0] == 'F')
        {
            totalunit += unit;
            continue;
        }
        else
        {
            score = 4 - (grade[0]-'A');
            if(grade[1] == '+')score += 0.5;
            sum += unit * score;
            totalunit += unit;
        }
    }
    printf("%lf", sum/totalunit);
    
    return 0;
}
