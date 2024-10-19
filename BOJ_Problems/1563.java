import java.util.Scanner;

public class Main {
    static final int MOD = 1000000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
         
        int[][][] dp = new int[N+1][2][3];
         
        dp[0][0][0] = 1;
 
        for (int i = 1; i <= N; i++) { 
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k]) % MOD;
                }
            }
 
            for (int k = 0; k <= 2; k++) {
                dp[i][1][0] = (dp[i][1][0] + dp[i-1][0][k]) % MOD;
            }
 
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 1; k++) {
                    dp[i][j][k+1] = (dp[i][j][k+1] + dp[i-1][j][k]) % MOD;
                }
            }
        }
 
        int result = 0;
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                result = (result + dp[N][j][k]) % MOD;
            }
        }
 
        System.out.println(result);
    }
}
