// You may use import as below.
//import java.util.*;

class Solution {
    public long solution(long num) {
        StringBuilder numAsString = new StringBuilder(String.valueOf(num + 1));

        for (int i = 0; i < numAsString.length(); i++) {
            if (numAsString.charAt(i) == '0') {
                numAsString.setCharAt(i, '1');
            }
        }

        long answer = Long.parseLong(numAsString.toString());

        return answer;
    }

    // The following is main method to output testcase.
    public static void main(String[] args) {
        Solution sol = new Solution();
        long num = 9949999;
        long ret = sol.solution(num);

        // Press Run button to receive output. 
        System.out.println("Solution: return value of the method is " + ret + " .");
    }
}