import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        System.out.println(get(n, m, 0));
    }

    static int get(int n, int m, int cnt) {
        if (n % m == 0) {
            return cnt;
        }
        
        if (n > m) {
            return get(n % m, m, cnt);
        }

        if (m % n == 0) {
            cnt += n * (m / n - 1);
            return cnt;
        }

        cnt += n * (m / n);
        m -= n * (m / n);
        return get(n, m, cnt);
    }
}
