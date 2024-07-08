// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public int solution(String s1, String s2) {
        int s1Len = s1.length();
        int s2Len = s2.length();
        int commonLen = 0;

        for (int len = 1; len <= Math.min(s1Len, s2Len); len++) {
            String s1Prefix = s1.substring(0, len);
            String s2Suffix = s2.substring(s2Len - len, s2Len);

            if (s1Prefix.equals(s2Suffix)) {
                commonLen = len;
            }

            String s2Prefix = s2.substring(0, len);
            String s1Suffix = s1.substring(s1Len - len, s1Len);

            if (s2Prefix.equals(s1Suffix)) {
                commonLen = len;
            }
        }

        int answer = s1Len + s2Len - commonLen;

        return answer;
    }
    
    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s1 = new String("ababc");
        String s2 = new String("abcdab");
        int ret = sol.solution(s1, s2);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret + " 입니다.");
    }
}