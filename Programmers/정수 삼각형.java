class Solution {
    public int solution(int[][] triangle) {
        int height = triangle.length;
 
        for (int row = height - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) { 
                triangle[row][col] += Math.max(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }
 
        return triangle[0][0];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] triangle = {
            {7},
            {3, 8},
            {8, 1, 0},
            {2, 7, 4, 4},
            {4, 5, 2, 6, 5}
        };
        
        int result = sol.solution(triangle);
        System.out.println("최대 경로의 합: " + result);  
    }
}
