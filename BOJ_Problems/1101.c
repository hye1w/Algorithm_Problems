#include <stdio.h>

#define MAX_N 1005
#define MAX_M 1005

typedef long long ll;

int main() {
    int n, m;
    scanf("%d %d", &n, &m); 

    int two = 0;
    int cnt[MAX_M] = {0};

    for (int i = 0; i < n; i++) {
        int c = 0;
        int have = -1;
        for (int j = 0; j < m; j++) {
            int k;
            scanf("%d", &k);
            if (k) c++, have = j;
        }
        if (c >= 2) two++;
        else if (c == 1) cnt[have]++;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans += (cnt[i] - 1 > 0) ? cnt[i] - 1 : 0;
    }
    if (two >= 1) ans += (two - 1 > 0) ? two - 1 : 0;
    else ans--;
    printf("%d\n", (ans > 0) ? ans : 0);

    return 0;
}
