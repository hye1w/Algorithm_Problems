import java.util.*;

public class Main {
    static int L, C;
    static char[] chars;
    static List<String> results = new ArrayList<>();
    static final List<Character> vowels = Arrays.asList('a', 'e', 'i', 'o', 'u');

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
         
        L = scanner.nextInt();
        C = scanner.nextInt();
         
        chars = new char[C];
        for (int i = 0; i < C; i++) {
            chars[i] = scanner.next().charAt(0);
        }
        Arrays.sort(chars);
 
        findPassword(0, 0, new StringBuilder());
         
        for (String password : results) {
            System.out.println(password);
        }
        
        scanner.close();
    }
 
    private static void findPassword(int start, int length, StringBuilder password) { 
        if (length == L) {
            if (isValid(password.toString())) {
                results.add(password.toString());
            }
            return;
        } 
        for (int i = start; i < C; i++) {
            password.append(chars[i]);
            findPassword(i + 1, length + 1, password);
            password.deleteCharAt(password.length() - 1);  // 백트래킹
        }
    } 
    private static boolean isValid(String password) {
        int vowelCount = 0;
        int consonantCount = 0;

        for (char ch : password.toCharArray()) {
            if (vowels.contains(ch)) {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
         
        return vowelCount >= 1 && consonantCount >= 2;
    }
}
