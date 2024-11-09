import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();   
        while (t-- > 0) {
            int n = scanner.nextInt();  
            String[] phoneNumbers = new String[n];
            for (int i = 0; i < n; i++) {
                phoneNumbers[i] = scanner.next();
            }
            System.out.println(isConsistent(phoneNumbers) ? "YES" : "NO");
        }
        scanner.close();
    }
 
    public static boolean isConsistent(String[] phoneNumbers) { 
        Arrays.sort(phoneNumbers);
        
        for (int i = 0; i < phoneNumbers.length - 1; i++) { 
            if (phoneNumbers[i + 1].startsWith(phoneNumbers[i])) {
                return false;   
            }
        }
        
        return true;   
    }
}
