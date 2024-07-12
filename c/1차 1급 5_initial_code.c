// You may use include as below.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_in_range(int num, int lower_include, int upper_exclude) {
    return lower_include <= num && num < upper_exclude;
}

int solution(int n) {
    int grid[100][100] = { 0, };
    int dir_rows[4] = { 0, 1, 0, -1 };
    int dir_cols[4] = { 1, 0, -1, 0 };
    int dir_idx = 0;
    int row = 0;
    int col = 0;
    int num = 1;
    
    while (num <= n * n) {
        grid[row][col] = num;
        
        int next_row = row + dir_rows[dir_idx];
        int next_col = col + dir_cols[dir_idx];
        
        if (!is_in_range(next_row, 0, n) || !is_in_range(next_col, 0, n) ||
            grid[next_row][next_col] != 0) {
            dir_idx = (dir_idx + 1) % 4;
        }
        
        row += dir_rows[dir_idx];
        col += dir_cols[dir_idx];
        num++;
    }

    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        answer += grid[i][i];
    }

    return answer;
}

// The following is main function to output testcase.
int main() {
    int n1 = 3;
    int ret1 = solution(n1);
    
    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret1);
    
    int n2 = 2;
    int ret2 = solution(n2);
    
    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret2);
}