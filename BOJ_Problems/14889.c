#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20

int N;
int S[MAX_N][MAX_N];
int visited[MAX_N];
int min = 1000000000;  

int calculateDifference(int team1[], int team2[]) {
    int abilityTeam1 = 0, abilityTeam2 = 0;

    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            abilityTeam1 += S[team1[i]][team1[j]];
            abilityTeam2 += S[team2[i]][team2[j]];
        }
    }
    return abs(abilityTeam1 - abilityTeam2);
}

void generateTeams(int depth, int start) {
    if (depth == N / 2) {
        int team1[N / 2], team2[N / 2];
        int index1 = 0, index2 = 0;

        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                team1[index1++] = i;
            } else {
                team2[index2++] = i;
            }
        }

        int difference = calculateDifference(team1, team2);

        if (difference < min) {
            min = difference;
        }
        return;
    }

    for (int i = start; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            generateTeams(depth + 1, i + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }
    generateTeams(0, 0);

    printf("%d\n", min);

    return 0;
}
