import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
         
        int N = sc.nextInt();  
        int M = sc.nextInt();  
        List<List<Integer>> graph = new ArrayList<>();
        int[] inDegree = new int[N + 1];  
         
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
         
        for (int i = 0; i < M; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            graph.get(A).add(B); 
            inDegree[B]++;       
        }
         
        PriorityQueue<Integer> pq = new PriorityQueue<>();
         
        for (int i = 1; i <= N; i++) {
            if (inDegree[i] == 0) {
                pq.add(i);
            }
        } 
        
        List<Integer> result = new ArrayList<>();
         
        while (!pq.isEmpty()) {
            int current = pq.poll();
            result.add(current);
             
            for (int next : graph.get(current)) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    pq.add(next); 
                }
            }
        }
         
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
