import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
 
        int[][] scores = new int[8][2];
 
        for (int i = 0; i < 8; i++) {
            int score = scanner.nextInt();
            scores[i][0] = score;    
            scores[i][1] = i + 1;    
        }
 
        Arrays.sort(scores, (a, b) -> b[0] - a[0]);

        int totalScore = 0;
        int[] selectedProblems = new int[5];
 
        for (int i = 0; i < 5; i++) {
            totalScore += scores[i][0];
            selectedProblems[i] = scores[i][1];
        }
 
        Arrays.sort(selectedProblems);
 
        System.out.println(totalScore);
        for (int problem : selectedProblems) {
            System.out.print(problem + " ");
        }
    }
}
