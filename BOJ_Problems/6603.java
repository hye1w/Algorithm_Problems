import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
 
    static List<Integer> result = new ArrayList<>();
 
    public static void combine(int[] S, int start, int depth, int k) {
        if (depth == 6) {
            for (int i = 0; i < 6; i++) {
                System.out.print(result.get(i) + " ");
            }
            System.out.println();
            return;
        }

        for (int i = start; i < k; i++) {
            result.add(S[i]);
            combine(S, i + 1, depth + 1, k);
            result.remove(result.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int k = sc.nextInt();
            if (k == 0) break;

            int[] S = new int[k];
            for (int i = 0; i < k; i++) {
                S[i] = sc.nextInt();
            }

            combine(S, 0, 0, k);
            System.out.println();
        }

        sc.close();
    }
}
