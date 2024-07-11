// 다음과 같이 import를 사용할 수 있습니다.
import java.util.*;

class Solution {
    public int solution(int[] card, int n) {
        Arrays.sort(card);
        List<Integer> numbers = permutations(card);
        int answer = numbers.indexOf(n);

        return (answer == -1) ? answer : answer + 1;
    }

    private List<Integer> permutations(int[] card) {
        int depth = 0;
        boolean[] visitedIdx = new boolean[card.length];
        int[] selected = new int[card.length];
        List<Integer> numbers = new ArrayList<>();

        Arrays.fill(visitedIdx, false);
        permutationsRecursive(card, depth, visitedIdx, selected, numbers);

        return numbers;
    }

    private void permutationsRecursive(int[] card, int depth, boolean[] visitedIdx, int[] selected, List<Integer> numbers) {
        if (depth == card.length) {
            int number = 0;

            for (int exp = 0; exp < card.length; exp++) {
                number += selected[card.length - exp - 1] * Math.pow(10, exp);
            }

            numbers.add(number);
            return;
        }

        boolean[] visitedNum = new boolean[10];
        Arrays.fill(visitedNum, false);

        for (int i = 0; i < card.length; i++) {
            int num = card[i];

            if (visitedNum[num] || visitedIdx[i]) {
                continue;
            }

            visitedNum[num] = true;
            visitedIdx[i] = true;

            selected[depth] = num;
            permutationsRecursive(card, depth + 1, visitedIdx, selected, numbers);

            visitedIdx[i] = false;
        }
    }
    
    // 아래는 테스트케이스 출력을 해보기 위한 main 메소드입니다.
    public static void main(String[] args) {
        Solution sol = new Solution();
        int card1[] = {1, 2, 1, 3};
        int n1 = 1312;
        int ret1 = sol.solution(card1, n1);

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret1 + " 입니다.");

        int card2[] = {1, 1, 1, 2};
        int n2 = 1122;
        int ret2 = sol.solution(card2, n2);
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("solution 메소드의 반환 값은 " + ret2 + " 입니다.");
    }    
}