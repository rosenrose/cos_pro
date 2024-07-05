// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public int[] solution(String commands) {
        int[] answer = { 0, 0 };
        int x = 0;
        int y = 0;

        for (int i = 0; i < commands.length(); i++) {
            switch (commands.charAt(i)) {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
            }
        };

        answer[0] = x;
        answer[1] = y;

        return answer;
    }

    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        String commands = "URDDL";
        int[] ret = sol.solution(commands);

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + Arrays.toString(ret) + " 입니다.");
    }
}