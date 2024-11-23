import java.util.Scanner;

public class Main {
    static int N, S, count = 0;
    static int[] arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
        N = sc.nextInt();
        S = sc.nextInt();
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
 
        findSubsequences(0, 0);
 
        if (S == 0) count--;
        System.out.println(count);
    }

    static void findSubsequences(int index, int sum) {
        if (index == N) {
            if (sum == S) {
                count++;
            }
            return;
        }
 
        findSubsequences(index + 1, sum + arr[index]);
 
        findSubsequences(index + 1, sum);
    }
}
