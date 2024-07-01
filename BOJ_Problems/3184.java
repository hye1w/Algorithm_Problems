import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int R, C;
    static char[][] yard;
    static boolean[][] visited;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        R = scanner.nextInt();
        C = scanner.nextInt();
        scanner.nextLine(); // consume the remaining newline

        yard = new char[R][C];
        visited = new boolean[R][C];

        for (int i = 0; i < R; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < C; j++) {
                yard[i][j] = line.charAt(j);
            }
        }

        int totalSheep = 0;
        int totalWolves = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!visited[i][j] && yard[i][j] != '#') {
                    int[] result = bfs(i, j);
                    int sheep = result[0];
                    int wolves = result[1];

                    if (sheep > wolves) {
                        totalSheep += sheep;
                    } else {
                        totalWolves += wolves;
                    }
                }
            }
        }

        System.out.println(totalSheep + " " + totalWolves);
    }

    static int[] bfs(int x, int y) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x, y});
        visited[x][y] = true;

        int sheep = 0;
        int wolves = 0;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int cx = current[0];
            int cy = current[1];

            if (yard[cx][cy] == 'o') {
                sheep++;
            } else if (yard[cx][cy] == 'v') {
                wolves++;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny] && yard[nx][ny] != '#') {
                    queue.add(new int[]{nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        return new int[]{sheep, wolves};
    }
}
