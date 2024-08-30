import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong(); 
        int F = sc.nextInt();   

        long newN = (N / 100) * 100;

        int result = 0;  

        for (int i = 0; i < 100; i++) {
            if ((newN + i) % F == 0) {
                result = i;  
                break;       
            }
        }

        System.out.printf("%02d", result);
    }
}
