#include <stdio.h>

typedef struct {
    int y, x, d;
} Fish;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int sharkEat; 

void calculateSum(int map[4][4], Fish fish[], int shark_x, int shark_y, int sum);

int main() {
    Fish fish[16];
    int map[4][4]; 

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            int a, b;
            scanf("%d %d ", &a, &b);
            --a, --b;

            fish[a].y = y;
            fish[a].x = x;
            fish[a].d = b;
            map[y][x] = a; 
        }
    }

    sharkEat = 0;
    calculateSum(map, fish, 0, 0, 0); 

    printf("%d\n", sharkEat);

    return 0;
}

void calculateSum(int map[4][4], Fish fish[], int shark_x, int shark_y, int sum) { 
    int cy_map[4][4];
    Fish cy_fish[16];

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cy_map[y][x] = map[y][x]; 
        }
    }
    for (int i = 0; i < 16; i++) {
        cy_fish[i] = fish[i];
    }

    int fish_num = cy_map[shark_y][shark_x];
    int shark_d = cy_fish[fish_num].d;
    cy_fish[fish_num].y = -1;
    cy_fish[fish_num].x = -1;
    cy_fish[fish_num].d = -1;
    cy_map[shark_y][shark_x] = -1;

    sum += (fish_num + 1);
    if (sharkEat < sum) {  
        sharkEat = sum; 
    }

    for (int f = 0; f < 16; f++) {
        if (cy_fish[f].y == -1) {
            continue;
        }

        int cy = cy_fish[f].y;
        int cx = cy_fish[f].x;
        int cd = cy_fish[f].d;

        int ny = cy + dy[cd];
        int nx = cx + dx[cd];
        int nd = cd;

        while (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == shark_y && nx == shark_x)) {
            nd = (nd + 1) % 8;
            ny = cy + dy[nd];
            nx = cx + dx[nd];
        }

        if (cy_map[ny][nx] != -1) {
            int target = cy_map[ny][nx];
            cy_fish[target].y = cy;
            cy_fish[target].x = cx;

            cy_fish[f].y = ny;
            cy_fish[f].x = nx;
            cy_fish[f].d = nd;

            cy_map[ny][nx] = f;
            cy_map[cy][cx] = target;
        } else {
            cy_fish[f].y = ny;
            cy_fish[f].x = nx;
            cy_fish[f].d = nd;

            cy_map[ny][nx] = f;
            cy_map[cy][cx] = -1;
        }
    }

    for (int m = 1; m < 4; m++) {
        int shark_ny = shark_y + dy[shark_d] * m;
        int shark_nx = shark_x + dx[shark_d] * m;

        if (shark_ny < 0 || shark_ny >= 4 || shark_nx < 0 || shark_nx >= 4) {
            break;
        }
        if (cy_map[shark_ny][shark_nx] != -1) {
            calculateSum(cy_map, cy_fish, shark_nx, shark_ny, sum); 
        }
    }
}
