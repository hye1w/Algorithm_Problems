import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine().trim());
        int K = Integer.parseInt(br.readLine().trim());
        
        int count = 0;
        
        for (int i = 1; i <= N; i++) {
            boolean isKJunNumber = true;
            int num = i;
            
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    while (num % j == 0) {
                        num /= j;
                    }
                    if (j > K) {
                        isKJunNumber = false;
                        break;
                    }
                }
            }
            
            if (num > 1 && num > K) {
                isKJunNumber = false;
            }
            
            if (isKJunNumber) {
                count++;
            }
        }
        
        System.out.println(count);
    }
}
