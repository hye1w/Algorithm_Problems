import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.close();

        int MOD = 10007;
        int[][] dp = new int[N + 1][10];
 
        for (int i = 0; i <= 9; i++) {
            dp[1][i] = 1;
        }
 
        for (int length = 2; length <= N; length++) {
            for (int end = 0; end <= 9; end++) {
                for (int prev = 0; prev <= end; prev++) {
                    dp[length][end] = (dp[length][end] + dp[length - 1][prev]) % MOD;
                }
            }
        } 
        
        int result = 0;
        for (int i = 0; i <= 9; i++) {
            result = (result + dp[N][i]) % MOD;
        }

        System.out.println(result);
    }
}
