import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
 
        int N = scanner.nextInt();
        Set<Integer> uniqueNumbers = new TreeSet<>(); 
        
        for (int i = 0; i < N; i++) {
            uniqueNumbers.add(scanner.nextInt());
        }
 
        for (int number : uniqueNumbers) {
            System.out.print(number + " ");
        }

        scanner.close();
    }
}
