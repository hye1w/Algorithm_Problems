#include <stdio.h>

int main(void) {

    int a;
    int b = 0;
    int arr[10];

    for (int i = 0 ; i < 10; i++) {
        scanf("%d", &a);
        arr[i] = (a % 42);
    }

    for (int i = 0; i < 10; i++) {

        int num = 0;

        for (int j = i + 1; j < 10; j++) { 

            if (arr[i] == arr[j])
                num++;    
        }

    if (num == 0)
        b++;
    }

    printf("%d", b);

    return 0;
}    
