import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();  
        
        int minPackagePrice = Integer.MAX_VALUE;  
        int minSinglePrice = Integer.MAX_VALUE;  
         
        for (int i = 0; i < M; i++) {
            int packagePrice = sc.nextInt();
            int singlePrice = sc.nextInt();
             
            minPackagePrice = Math.min(minPackagePrice, packagePrice);
            minSinglePrice = Math.min(minSinglePrice, singlePrice);
        }
         
        int costByPackageOnly = ((N + 5) / 6) * minPackagePrice; 
         
        int costBySingleOnly = N * minSinglePrice;
         
        int costByMix = (N / 6) * minPackagePrice + (N % 6) * minSinglePrice;
         
        int result = Math.min(costByPackageOnly, Math.min(costBySingleOnly, costByMix));
         
        System.out.println(result);
    }
}
