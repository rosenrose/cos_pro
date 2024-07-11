// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public String solution(int hour, int minute) {
        double hourDegree = (hour % 12 * 30) + (minute * 0.5);
        double minuteDegree = minute * 6;
        double angle = Math.abs(hourDegree - minuteDegree);

        if (angle > 180) {
            angle = 360 - angle;
        }

        String answer = String.format("%.1f", angle);
        return answer;
    }

    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        int hour = 3;
        int minute = 0;
        String ret = sol.solution(hour, minute);

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret + " 입니다.");
    }
}