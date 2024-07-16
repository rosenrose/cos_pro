// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public int solution(int K, String[] words) {
        int answer = 1;
        int length = 0;

        for (int i = 0; i < words.length; i++) {
            int word_len = words[i].length();

            if (length + word_len <= K) {
                length += word_len;
            } else {
                length = word_len;
                answer++;
            }

            if (i == words.length - 1) {
                continue;
            }

            if (length + 1 <= K) {
                length += 1;
            } else {
                length = 0;
                answer++;
            }
        }

        return answer;
    }

    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        int K = 10;
        String[] words = {new String("nice"), new String("happy"), new String("hello"), new String("world"), new String("hi")};
        int ret = sol.solution(K, words);

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소의 반환 값은 " + ret + " 입니다.");
    }
}