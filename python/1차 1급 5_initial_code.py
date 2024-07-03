#You may use import as below.
#import math

def solution(n):
    grid = [[0 for i in range(100)] for j in range(100)]
    dir_rows = [0, 1, 0, -1]
    dir_cols = [1, 0, -1, 0]
    dir_idx = 0
    row = 0
    col = 0
    num = 1
    
    while num <= n * n:
        grid[row][col] = num
        
        next_row = row + dir_rows[dir_idx]
        next_col = col + dir_cols[dir_idx]
        
        if next_row not in range(0, n) or next_col not in range(0, n) or grid[next_row][next_col] != 0:
            dir_idx = (dir_idx + 1) % 4
        
        row += dir_rows[dir_idx]
        col += dir_cols[dir_idx]
        num += 1

    answer = 0
    
    for i in range(n):
        answer += grid[i][i]

    return answer

#The following is code to output testcase.
n1 = 3
ret1 = solution(n1)

#Press Run button to receive output. 
print("Solution: return value of the function is", ret1, ".")
    
n2 = 2
ret2 = solution(n2)

#Press Run button to receive output. 
print("Solution: return value of the function is", ret2, ".")