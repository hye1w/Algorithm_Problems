import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();  
        int m = scanner.nextInt();  

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        int minKevinBacon = Integer.MAX_VALUE;
        int resultUser = -1;

        for (int i = 1; i <= n; i++) {
            int kevinBacon = bfs(i, graph, n);
            if (kevinBacon < minKevinBacon) {
                minKevinBacon = kevinBacon;
                resultUser = i;
            }
        }

        System.out.println(resultUser);
    }

    private static int bfs(int start, List<List<Integer>> graph, int n) {
        boolean[] visited = new boolean[n + 1];
        int[] distances = new int[n + 1];

        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = true;

        while (!queue.isEmpty()) {
            int current = queue.poll();

            for (int neighbor : graph.get(current)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distances[neighbor] = distances[current] + 1;
                    queue.add(neighbor);
                }
            }
        }

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += distances[i];
        }
        return sum;
    }
}
