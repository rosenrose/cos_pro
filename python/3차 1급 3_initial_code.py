#다음과 같이 import를 사용할 수 있습니다.
#import math

def solution(bishops):
    checked = [[False for _ in range(8)] for _ in range(8)]
    dirs_row = [-1, -1, 1, 1]
    dirs_col = [-1, 1, -1, 1]
    answer = 8 * 8

    for bishop in bishops:
        for dir_idx in range(0, 4):
            row = ord(bishop[1]) - ord("1")
            col = ord(bishop[0]) - ord("A")

            while row in range(0, 8) and col in range(0, 8):
                if not checked[row][col]:
                    checked[row][col] = True
                    answer -= 1

                row += dirs_row[dir_idx]
                col += dirs_col[dir_idx]

    return answer

#아래는 테스트케이스 출력을 해보기 위한 코드입니다.
bishops1 = ["D5"]
ret1 = solution(bishops1)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret1, "입니다.")

bishops2 = ["D5", "E8", "G2"]
ret2 = solution(bishops2)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret2, "입니다.")