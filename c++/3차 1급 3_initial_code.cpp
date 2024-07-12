// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_in_range(int num, int lower_include, int upper_exclude) {
    return lower_include <= num && num < upper_exclude;
}

int solution(vector<string> bishops) {
    bool checked[8][8] = { false , };
    int dirs_row[4] = { -1, -1, 1, 1 };
    int dirs_col[4] = { -1, 1, -1, 1 };
    int answer = 8 * 8;

    for (auto bishop : bishops) {
        for (int dir_idx = 0; dir_idx < 4; dir_idx++) {
            int row = bishop[1] - '1';
            int col = bishop[0] - 'A';

            while (is_in_range(row, 0, 8) && is_in_range(col, 0, 8)) {
                if (!checked[row][col]) {
                    checked[row][col] = true;
                    answer--;
                }

                row += dirs_row[dir_idx];
                col += dirs_col[dir_idx];
            }
        }
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<string>  bishops1 = {"D5"};
    int ret1 = solution( bishops1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    vector<string>  bishops2 = {"D5", "E8", "G2"};
    int ret2 = solution( bishops2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}