import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
 
        String target = scanner.nextLine();
 
        int N = scanner.nextInt();
        scanner.nextLine();

        int count = 0; 
        
        for (int i = 0; i < N; i++) {
            // 반지의 문자열 입력
            String ring = scanner.nextLine();
            for (int j = 0; j < ring.length(); j++) {
                if (ring.charAt(j) == target.charAt(0)) {
                    int k = j;
                    int m = 0;
                    while (m < target.length() && ring.charAt(k) == target.charAt(m)) {
                        k = (k + 1) % ring.length(); 
                        m++;
                    } 
                    if (m == target.length()) {
                        count++;
                        break;  
                    }
                }
            }
        }
 
        System.out.println(count);

        scanner.close();
    }
}
