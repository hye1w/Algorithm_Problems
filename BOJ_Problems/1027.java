import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); 
        int[] heights = new int[N];  
        
        for (int i = 0; i < N; i++) {
            heights[i] = sc.nextInt();  
        }
        
        int maxVisible = 0;
        for (int i = 0; i < N; i++) {
            int visible = countVisibleBuildings(heights, i);  
            maxVisible = Math.max(maxVisible, visible);  
        }
        
        System.out.println(maxVisible);  
    }
     
    private static int countVisibleBuildings(int[] heights, int current) {
        int count = 0;
         
        boolean firstBuilding = true;
        double lastSlope = 0;
        for (int i = current - 1; i >= 0; i--) {
            double slope = (double)(heights[i] - heights[current]) / (current - i);  
            if (firstBuilding || slope > lastSlope) {  
                lastSlope = slope;
                count++;
                firstBuilding = false; 
            }
        }
         
        firstBuilding = true;
        lastSlope = 0;
        for (int i = current + 1; i < heights.length; i++) {
            double slope = (double)(heights[i] - heights[current]) / (i - current);  
            if (firstBuilding || slope > lastSlope) { 
                lastSlope = slope;
                count++;
                firstBuilding = false;  
            }
        }
        
        return count;
    }
}
