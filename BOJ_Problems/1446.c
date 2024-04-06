#include <stdio.h>
#include <stdlib.h>
 
int compare(const void *a, const void *b) {
    int *arr1 = (int *)a;
    int *arr2 = (int *)b;
    return arr1[0] - arr2[0];
}

int main() {
    int N, D;
    scanf("%d %d", &N, &D);

    int short_road_info[N][3]; // 0: 시작 위치, 1: 도착 위치, 2: 지름길의 길이

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &short_road_info[i][0], &short_road_info[i][1], &short_road_info[i][2]);
    }

    qsort(short_road_info, N, sizeof(short_road_info[0]), compare);

    int visit_loc[D + 1];
    for (int i = 0; i <= D; i++) {
        visit_loc[i] = 0;
    }

    int dp[D + 1];
    for (int i = 0; i <= D; i++) {
        dp[i] = i;
    }

    for (int i = 0; i < N; i++) {
        int S = short_road_info[i][0];
        int E = short_road_info[i][1];
        int road_length = short_road_info[i][2];

        if (E > D || E - S < road_length) {
            continue;
        }

        visit_loc[S] = 1;
        visit_loc[E] = 1;

        for (int j = 0; j <= D; j++) {
            if (S > j && visit_loc[j]) {
                dp[S] = (dp[S] < dp[j] + (S - j)) ? dp[S] : dp[j] + (S - j);
            }
        }

        dp[E] = (dp[E] < dp[S] + road_length) ? dp[E] : dp[S] + road_length;
        dp[D] = (dp[D] < dp[E] + (D - E)) ? dp[D] : dp[E] + (D - E);
    }

    printf("%d\n", dp[D]);

    return 0;
}
