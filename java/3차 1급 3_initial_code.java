// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public int solution(String[] bishops) {
        Boolean[][] checked = new Boolean[8][8];
        int[] dirs_row = { -1, -1, 1, 1 };
        int[] dirs_col = { -1, 1, -1, 1 };
        int answer = 8 * 8;

        for (Boolean[] row : checked) {
            Arrays.fill(row, false);
        }

        for (String bishop : bishops) {
            for (int dir_idx = 0; dir_idx < 4; dir_idx++) {
                int row = bishop.charAt(1) - '1';
                int col = bishop.charAt(0) - 'A';

                while (isInRange(row, 0, 8) && isInRange(col, 0, 8)) {
                    if (!checked[row][col]) {
                        checked[row][col] = true;
                        answer--;
                    }

                    row += dirs_row[dir_idx];
                    col += dirs_col[dir_idx];
                }
            }
        }

        return answer;
    }

    private Boolean isInRange(int num, int lowerInclude, int upperExclude) {
        return lowerInclude <= num && num < upperExclude;
    }

    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] bishops1 = {new String("D5")};
        int ret1 = sol.solution(bishops1);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret1 + " 입니다.");

        String[] bishops2 = {new String("D5"), new String("E8"), new String("G2")};
        int ret2 = sol.solution(bishops2);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret2 + " 입니다.");
    }
}