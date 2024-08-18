import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        
        for (int l = L; l <= 100; l++) {
            int temp = N - (l * (l - 1)) / 2;
            
            if (temp % l == 0) {
                int x = temp / l;
                
                if (x >= 0) {
                    for (int i = 0; i < l; i++) {
                        System.out.print((x + i) + " ");
                    }
                    return;
                }
            }
        }
        
        System.out.println("-1");
    }
}
