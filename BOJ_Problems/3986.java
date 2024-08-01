import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();
        scanner.nextLine();  
        
        int goodWordsCount = 0;

        for (int i = 0; i < N; i++) {
            String word = scanner.nextLine();
            if (isGoodWord(word)) {
                goodWordsCount++;
            }
        }
       
        System.out.println(goodWordsCount);
        
        scanner.close();
    }
    
    private static boolean isGoodWord(String word) {
        Stack<Character> stack = new Stack<>();
        
        for (char c : word.toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == c) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        
        return stack.isEmpty();
    }
}
