#다음과 같이 import를 사용할 수 있습니다.
from collections import deque

MAX_NUM = 10000

def solution(number, target):
    steps = [-1] * (MAX_NUM + 1)
    steps[number] = 0
    queue = deque([number])

    while queue:
        num = queue.popleft()
        adjacents = [num + 1, num - 1, num * 2]

        for adj in adjacents:
            if adj not in range(0, MAX_NUM + 1) or steps[adj] != -1:
                continue

            steps[adj] = steps[num] + 1
            queue.append(adj)

    answer = steps[target]

    return answer

#아래는 테스트케이스 출력을 해보기 위한 코드입니다.
number1 = 5
target1 = 9
ret1 = solution(number1, target1)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret1, "입니다.")

number2 = 3
target2 = 11
ret2 = solution(number2, target2)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret2, "입니다.")