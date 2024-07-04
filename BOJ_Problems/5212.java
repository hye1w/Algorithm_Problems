import java.util.Scanner;

public class Main {
    static int R, C;
    static char[][] map;
    static char[][] futureMap;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        R = sc.nextInt();
        C = sc.nextInt();
        map = new char[R][C];
        futureMap = new char[R][C];

        for (int i = 0; i < R; i++) {
            String line = sc.next();
            for (int j = 0; j < C; j++) {
                map[i][j] = line.charAt(j);
                futureMap[i][j] = map[i][j];
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] == 'X') {
                    int seaCount = 0;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni < 0 || nj < 0 || ni >= R || nj >= C || map[ni][nj] == '.') {
                            seaCount++;
                        }
                    }
                    if (seaCount >= 3) {
                        futureMap[i][j] = '.';
                    }
                }
            }
        }

        int minRow = R, maxRow = 0, minCol = C, maxCol = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (futureMap[i][j] == 'X') {
                    if (i < minRow) minRow = i;
                    if (i > maxRow) maxRow = i;
                    if (j < minCol) minCol = j;
                    if (j > maxCol) maxCol = j;
                }
            }
        }

        for (int i = minRow; i <= maxRow; i++) {
            for (int j = minCol; j <= maxCol; j++) {
                System.out.print(futureMap[i][j]);
            }
            System.out.println();
        }
    }
}
