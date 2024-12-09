import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        
        int result = getMinimumCoins(n);
        System.out.println(result);
    }

    public static int getMinimumCoins(int n) {
        int count = 0;

        while (n > 0) {
            if (n % 5 == 0) {
                count += n / 5;
                return count;
            }
            n -= 2;
            count++;
        }

        return n == 0 ? count : -1;
    }
}
