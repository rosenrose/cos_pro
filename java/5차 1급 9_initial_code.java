// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
	static final int MAX_NUM = 10000;

	public int solution(int number, int target) {
		int[] steps = new int[MAX_NUM + 1];
		Deque<Integer> queue = new ArrayDeque<>();

		Arrays.fill(steps, -1);
		steps[number] = 0;
		queue.addLast(number);

		while (!queue.isEmpty()) {
			int num = queue.removeFirst();
			int[] adjacents = { num + 1, num - 1, num * 2 };

			for (int adj : adjacents) {
				if (!isInRange(adj, 0, MAX_NUM + 1) || steps[adj] != -1) {
					continue;
				}

				steps[adj] = steps[num] + 1;
				queue.addLast(adj);
			}
		}

		int answer = steps[target];

		return answer;
	}

	private boolean isInRange(int num, int lowerInclude, int upperExclude) {
        return lowerInclude <= num && num < upperExclude;
    }

	// 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
	public static void main(String[] args) {
		Solution sol = new Solution();
		int number1 = 5;
		int target1 = 9;
		int ret1 = sol.solution(number1, target1);

		// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
		System.out.println("solution 메소드의 반환 값은 " + ret1 + " 입니다.");

		int number2 = 3;
		int target2 = 11;
		int ret2 = sol.solution(number2, target2);

		// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
		System.out.println("solution 메소드의 반환 값은 " + ret2 + " 입니다.");
	}
}