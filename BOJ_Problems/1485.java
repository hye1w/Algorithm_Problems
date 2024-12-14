import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
 
        int T = scanner.nextInt();
 
        for (int t = 0; t < T; t++) { 
            int[][] points = new int[4][2];
            for (int i = 0; i < 4; i++) {
                points[i][0] = scanner.nextInt(); 
                points[i][1] = scanner.nextInt();  
            } 
            System.out.println(isSquare(points) ? 1 : 0);
        } 
        scanner.close();
    }
 
    private static int distanceSquared(int[] p1, int[] p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
 
    private static boolean isSquare(int[][] points) {
        int[] distances = new int[6];
        int index = 0;
 
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                distances[index++] = distanceSquared(points[i], points[j]);
            }
        } 
        Arrays.sort(distances);
 
        return distances[0] > 0  
                && distances[0] == distances[1]
                && distances[1] == distances[2]
                && distances[2] == distances[3]
                && distances[4] == distances[5]
                && distances[0] * 2 == distances[4];
    }
}
