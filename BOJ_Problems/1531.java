import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        int[][] grid = new int[101][101];
        
        for (int i = 0; i < N; i++) {
            int x1 = scanner.nextInt();
            int y1 = scanner.nextInt();
            int x2 = scanner.nextInt();
            int y2 = scanner.nextInt();

            for (int x = x1; x <= x2; x++) {
                for (int y = y1; y <= y2; y++) {
                    grid[x][y]++;
                }
            }
        }

        int invisibleCount = 0;
        for (int x = 1; x <= 100; x++) {
            for (int y = 1; y <= 100; y++) {
                if (grid[x][y] > M) {
                    invisibleCount++;
                }
            }
        }

        System.out.println(invisibleCount);

        scanner.close();
    }
}
