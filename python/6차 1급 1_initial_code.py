from collections import deque

def solution(n, garden):
    answer = 0
    queue = deque()

    for r in range(len(garden)):
        for c in range(len(garden[r])):
            if garden[r][c] ==0:
                continue
            
            queue.append((r, c, 0))

    while queue:
        row, col, day = queue.popleft()
        adjacents = [
            (row - 1, col, day + 1),
            (row, col - 1, day + 1),
            (row + 1, col, day + 1),
            (row, col + 1, day + 1)
        ]

        for adj in adjacents:
            adj_row, adj_col, adj_day = adj

            if adj_row not in range(0, n) or adj_col not in range(0, n) or garden[adj_row][adj_col] == 1:
                continue

            garden[adj_row][adj_col] = 1
            answer = max(adj_day, answer)
            queue.append(adj)

    return answer

#아래는 테스트케이스 출력을 해보기 위한 코드입니다.
n1 = 3
garden1 = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
ret1 = solution(n1, garden1)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret1, "입니다.")

n2 = 2
garden2 = [[1, 1], [1, 1]]
ret2 = solution(n2, garden2)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret2, "입니다.")