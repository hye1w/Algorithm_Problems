import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
         
        String document = scanner.nextLine();
        String word = scanner.nextLine();
        
        int count = 0;  
        int index = 0;  
         
        while ((index = document.indexOf(word, index)) != -1) {
            count++; 
            index += word.length();
        }
         
        System.out.println(count);
        
        scanner.close();
    }
}
