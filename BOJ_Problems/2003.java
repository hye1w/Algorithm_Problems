import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] A = new int[N];
        
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        
        int count = 0;  
        int sum = 0; 
        int end = 0;    
        
        for (int start = 0; start < N; start++) {
            
            while (sum < M && end < N) {
                sum += A[end];
                end++;
            }
            
            if (sum == M) {
                count++;
            }
            
            sum -= A[start];
        }
        
        System.out.println(count);
        sc.close();
    }
}
