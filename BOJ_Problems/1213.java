import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
         
        int[] freq = new int[26];
        for (char c : name.toCharArray()) {
            freq[c - 'A']++;  
        }
         
        int oddCount = 0;
        int oddCharIndex = -1;  
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                oddCount++;
                oddCharIndex = i;
            }
        }
         
        if (oddCount > 1) {
            System.out.println("I'm Sorry Hansoo");
            return;
        }
         
        StringBuilder half = new StringBuilder();  
        for (int i = 0; i < 26; i++) { 
            for (int j = 0; j < freq[i] / 2; j++) {
                half.append((char) (i + 'A'));
            }
        }
        
        StringBuilder palindrome = new StringBuilder(half); 
        if (oddCharIndex != -1) { 
            palindrome.append((char) (oddCharIndex + 'A'));
        }
        palindrome.append(half.reverse());  
         
        System.out.println(palindrome.toString());
    }
}
