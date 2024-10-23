import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
         
        String roomNumber = sc.next();
         
        int[] count = new int[10];
         
        for (char c : roomNumber.toCharArray()) {
            int digit = c - '0';
            count[digit]++;
        }
          
        int sixNineCount = count[6] + count[9];
        count[6] = (sixNineCount + 1) / 2; 
         
        count[9] = 0;
         
        int maxSetCount = 0;
        for (int i = 0; i < 10; i++) {
            if (count[i] > maxSetCount) {
                maxSetCount = count[i];
            }
        } 
        System.out.println(maxSetCount);
        
        sc.close();
    }
}
