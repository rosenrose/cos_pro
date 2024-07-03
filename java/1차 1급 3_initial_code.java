// You may use import as below.
//import java.util.*;

class Solution {
    public int solution(String pos) {
        int row = pos.charAt(1) - '1';
        int col = pos.charAt(0) - 'A';
        int[] dirRows = { -1, -2, -2, -1, 1, 2, 2, 1 };
        int[] dirCols = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int answer = 0;

        for (int i = 0; i < 8; i++) {
            int nextRow = row + dirRows[i];
            int nextCol = col + dirCols[i];

            if ((0 <= nextRow && nextRow < 8) && (0 <= nextCol && nextCol < 8)) {
                answer++;
            }
        }

        return answer;
    }

    // The following is main method to output testcase.
    public static void main(String[] args) {
        Solution sol = new Solution();
        String pos = "A7";
        int ret = sol.solution(pos);

        // Press Run button to receive output. 
        System.out.println("Solution: return value of the method is " + ret + " .");
    }
}