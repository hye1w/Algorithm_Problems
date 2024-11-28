import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
         
        double W = scanner.nextDouble();
        double L = scanner.nextDouble();
        double D = scanner.nextDouble();
        scanner.close();
        
        int initialScore = 2000;
        int games = 20;
        int maxScore = 3500; 
        int minScore = 1000;
        
        double[][] dp = new double[games + 1][maxScore + 1];
        dp[0][initialScore] = 1.0; 
        
        for (int game = 0; game < games; game++) {
            for (int score = minScore; score <= maxScore; score++) {
                if (dp[game][score] > 0) { 
                    int winScore = Math.min(score + 50, maxScore);
                    dp[game + 1][winScore] += dp[game][score] * W;
                     
                    int loseScore = Math.max(score - 50, minScore);
                    dp[game + 1][loseScore] += dp[game][score] * L;
                     
                    dp[game + 1][score] += dp[game][score] * D;
                }
            }
        }
         
        double bronze = 0, silver = 0, gold = 0, platinum = 0, diamond = 0;
        for (int score = minScore; score <= maxScore; score++) {
            if (score >= 1000 && score <= 1499) {
                bronze += dp[games][score];
            } else if (score >= 1500 && score <= 1999) {
                silver += dp[games][score];
            } else if (score >= 2000 && score <= 2499) {
                gold += dp[games][score];
            } else if (score >= 2500 && score <= 2999) {
                platinum += dp[games][score];
            } else if (score >= 3000 && score <= 3499) {
                diamond += dp[games][score];
            }
        }
         
        System.out.printf("%.8f\n", bronze);
        System.out.printf("%.8f\n", silver);
        System.out.printf("%.8f\n", gold);
        System.out.printf("%.8f\n", platinum);
        System.out.printf("%.8f\n", diamond);
    }
}
