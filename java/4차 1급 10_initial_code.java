// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public int solution(int a, int b) {
        int answer = 0;

        for (int num = 2; num * num <= b; num++) {
            if (!isPrime(num)) {
                continue;
            }

            if (isInRange(num * num, a, b + 1)) {
                answer++;
            }
            if (isInRange(num * num * num, a, b + 1)) {
                answer++;
            }

        }

        return answer;
    }

    private boolean isPrime(int num) {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    private boolean isInRange(int num, int lowerInclude, int upperExclude) {
        return lowerInclude <= num && num < upperExclude;
    }

    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args){
        Solution sol = new Solution();
        int a = 6;
        int b = 30;
        int ret = sol.solution(a, b);

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret + " 입니다.");
    }
}