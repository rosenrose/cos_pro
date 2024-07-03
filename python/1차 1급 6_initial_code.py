#You may use import as below.
#import math

def solution(pos):
    row = ord(pos[1]) - ord("1")
    col = ord(pos[0]) - ord("A")
    dir_rows = [-1, -2, -2, -1, 1, 2, 2, 1]
    dir_cols = [-2, -1, 1, 2, -2, -1, 1, 2]
    answer = 0

    for i in range(8):
        next_row = row + dir_rows[i]
        next_col = col + dir_cols[i]

        if next_row in range(0, 8) and next_col in range(0, 8):
            answer += 1

    return answer

#The following is code to output testcase.
pos = "A7"
ret = solution(pos)

#Press Run button to receive output.
print("Solution: return value of the function is", ret, ".")