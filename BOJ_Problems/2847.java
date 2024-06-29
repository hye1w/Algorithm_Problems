import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
         
        int N = sc.nextInt();
        int[] scores = new int[N];
 
        for (int i = 0; i < N; i++) {
            scores[i] = sc.nextInt();
        }
        
        // 감소 횟수를 저장할 변수
        int decreaseCount = 0;
        
        // 뒤에서부터 점수를 확인하면서 필요한 경우 감소
        for (int i = N - 2; i >= 0; i--) {
            if (scores[i] >= scores[i + 1]) {
                // scores[i]가 scores[i + 1]보다 크거나 같은 경우 점수 감소 
                int decreaseAmount = scores[i] - scores[i + 1] + 1;
                scores[i] -= decreaseAmount;
                decreaseCount += decreaseAmount;
            }
        }
         
        System.out.println(decreaseCount);
        
        sc.close();
    }
}
