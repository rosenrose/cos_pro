// You may use import as below.
//import java.util.*;

class Solution {
    public int solution(int n) {
        int[][] grid = new int[100][100];
        int[] dirRows = { 0, 1, 0, -1 };
        int[] dirCols = { 1, 0, -1, 0 };
        int dirIdx = 0;
        int row = 0;
        int col = 0;
        int num = 1;
        
        while (num <= n * n) {
            grid[row][col] = num;
            
            int nextRow = row + dirRows[dirIdx];
            int nextCol = col + dirCols[dirIdx];
            
            if (!isInRange(nextRow, 0, n) || !isInRange(nextCol, 0, n) ||
                grid[nextRow][nextCol] != 0) {
                dirIdx = (dirIdx + 1) % 4;
            }
            
            row += dirRows[dirIdx];
            col += dirCols[dirIdx];
            num++;
        }

        int answer = 0;
        
        for (int i = 0; i < n; i++) {
            answer += grid[i][i];
        }

        return answer;
    }

    private boolean isInRange(int num, int lowerInclude, int upperExclude) {
        return lowerInclude <= num && num < upperExclude;
    }

    // The following is main method to output testcase.
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n1 = 3;
        int ret1 = sol.solution(n1);

        
        // Press Run button to receive output. 
        System.out.println("Solution: return value of the method is " + ret1 + " .");
        
        int n2 = 2;
        int ret2 = sol.solution(n2);
        
        // Press Run button to receive output. 
        System.out.println("Solution: return value of the method is " + ret2 + " .");
    }
}