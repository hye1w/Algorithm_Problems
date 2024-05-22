#include <stdio.h>

int gcd(int a, int b) {

    while (b != 0) { 
        int t = b; 
        b = a % b; 
        a = t; 
    } 
    return a;

}

int lcm(int a, int b) { 
    return a * (b / gcd(a, b)); 
}

int lcm_three(int a, int b, int c) { 
    return lcm(a, lcm(b, c)); 
}

int main() { 
    int arr[5]; 
    int min = 101 * 101 * 101;

    for (int i = 0; i < 5; i++) { 
        scanf("%d", &arr[i]); 
    }

    for (int i = 0; i < 5; i++) { 
        for (int j = i + 1; j < 5; j++) { 
            for (int k = j + 1; k < 5; k++) { 
                int c_lcm = lcm_three(arr[i], arr[j], arr[k]); 
                if (c_lcm < min) { 
                    min = c_lcm; 
                } 
            } 
        } 
    } 
    printf("%d", min);

    return 0; 
} 
