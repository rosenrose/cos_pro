// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public String solution(String phrases, int second) {
        String placeholder = "______________";
        String totalText = String.format("%s%s%s", placeholder, phrases, placeholder);

        second %= 28;
        String answer = totalText.substring(second, second + placeholder.length());

        return answer;
    }
    
    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        String phrases = new String("happy-birthday");
        int second = 3;
        String ret = sol.solution(phrases, second);
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret + " 입니다.");
    }
}