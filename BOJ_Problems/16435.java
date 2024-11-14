import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt();  
        int l = scanner.nextInt();   
        int[] heights = new int[n]; 

        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextInt();
        }
 
        Arrays.sort(heights);
 
        for (int height : heights) {
            if (height <= l) {
                l++;  
            } else {
                break;  
            }
        }
 
        System.out.println(l);

        scanner.close();
    }
}
