// You may use include as below.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string pos) {
    int row = pos[1] - '1';
    int col = pos[0] - 'A';
    int dir_rows[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int dir_cols[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int answer = 0;
    
    for (int i = 0; i < 8; i++) {
        int next_row = row + dir_rows[i];
        int next_col = col + dir_cols[i];
        
        if ((0 <= next_row && next_row < 8) && (0 <= next_col && next_col < 8)) {
            answer++;
        }
    }
    
    return answer;
}

// The following is main function to output testcase.
int main() {
    string pos = "A7";
    int ret = solution(pos);

    // Press Run button to receive output. 
    cout << "Solution: return value of the function is " << ret << " ." << endl;
}