import java.util.*;

public class Main {
    static int N, M;
    static int[] numbers;
    static boolean[] visited;
    static List<Integer> sequence = new ArrayList<>();
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
         
        N = sc.nextInt();
        M = sc.nextInt();
        numbers = new int[N];
        visited = new boolean[N];
        
        for (int i = 0; i < N; i++) {
            numbers[i] = sc.nextInt();
        }
         
        Arrays.sort(numbers);
         
        backtrack(0);
    }
    
    public static void backtrack(int depth) { 
        if (depth == M) {
            for (int num : sequence) {
                System.out.print(num + " ");
            }
            System.out.println();
            return;
        }
         
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sequence.add(numbers[i]);
                
                backtrack(depth + 1);
                 
                visited[i] = false;
                sequence.remove(sequence.size() - 1);
            }
        }
    }
}
