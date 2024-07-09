// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_in_range(int num, int lowerInclude, int upperExclude) {
    return lowerInclude <= num && num < upperExclude;
}

int solution(char* bishops[], int bishops_len) {
    bool checked[8][8] = { false , };
    int dirs_row[4] = { -1, -1, 1, 1 };
    int dirs_col[4] = { -1, 1, -1, 1 };
    int answer = 8 * 8;

    for (int i = 0; i < bishops_len; i++) {
        for (int dir_idx = 0; dir_idx < 4; dir_idx++) {
            int row = bishops[i][1] - '1';
            int col = bishops[i][0] - 'A';

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
    char* bishops1[1] = {"D5"};
    int bishops1_len = 1;
    int ret1 = solution(bishops1, bishops1_len);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

    char* bishops2[3] = {"D5", "E8", "G2"};
    int bishops2_len = 3;
    int ret2 = solution(bishops2, bishops2_len);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
}