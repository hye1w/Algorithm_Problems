#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int lengths[3] = {a, b, c};
    for (int i = 0; i < 2; i++) 
    {
        for (int j = i + 1; j < 3; j++) 
        {
            if (lengths[i] < lengths[j]) 
            {
                int temp = lengths[i];
                lengths[i] = lengths[j];
                lengths[j] = temp;
            }
        }
    }

    if (lengths[0] < lengths[1] + lengths[2]) {
        printf("%d\n", lengths[0] + lengths[1] + lengths[2]);
    } else {
        lengths[0] = lengths[1] + lengths[2] - 1;
        printf("%d\n", lengths[0] + lengths[1] + lengths[2]);
    }
    return 0;
}
