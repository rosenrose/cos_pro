// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Flower {
	int row;
    int col;
    int day;

	Flower(int row, int col, int day) {
		this.row = row;
		this.col = col;
		this.day = day;
	}
}

class Solution {
    public int solution(int n, int[][] garden) {
        int answer = 0;
        Deque<Flower> queue = new ArrayDeque<>();

        for (int r = 0; r < garden.length; r++) {
            for (int c = 0; c < garden[r].length; c++) {
                if (garden[r][c] == 0) {
                    continue;
                }

                queue.addLast(new Flower(r, c, 0));
            }
        }

        while(!queue.isEmpty()) {
            Flower flower = queue.removeFirst();
            Flower[] adjacents = {
                new Flower(flower.row - 1, flower.col, flower.day + 1),
                new Flower(flower.row, flower.col - 1, flower.day + 1),
                new Flower(flower.row + 1, flower.col, flower.day + 1),
                new Flower(flower.row, flower.col + 1, flower.day + 1)
            };

            for (Flower adj : adjacents) {
                if (!isInRange(adj.row, 0, n) || !isInRange(adj.col, 0, n) || garden[adj.row][adj.col] == 1) {
                    continue;
                }

                garden[adj.row][adj.col] = 1;
                answer = Math.max(adj.day, answer);
                queue.addLast(adj);
            }
        }

        return answer;
    }
    
    private boolean isInRange(int num, int lowerInclude, int upperExclude) {
        return lowerInclude <= num && num < upperExclude;
    }

    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n1 = 3;
        int[][] garden1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        int ret1 = sol.solution(n1, garden1);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret1 + " 입니다.");
        
        int n2 = 2;
        int[][] garden2 = {{1, 1}, {1, 1}};
        int ret2 = sol.solution(n2, garden2);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret2 + " 입니다.");
        
    }    
}