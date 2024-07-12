// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Flower {
    int row;
    int col;
    int day;
}Flower;

bool is_in_range(int num, int lower_include, int upper_exclude) {
    return lower_include <= num && num < upper_exclude;
}

int solution(int n, int garden[][n]) {
    Flower* queue = (Flower*)calloc(sizeof(Flower), 100 * 100);
    int queue_head = 0;
    int queue_tail = 0;
    int answer = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (garden[r][c] == 0) {
                continue;
            }

            Flower flower = { r, c, 0 };
            queue[queue_tail] = flower;
            queue_tail++;
        }
    }

    while (queue_head <= queue_tail) {
        Flower flower = queue[queue_head];
        Flower adjacents[4] = {
            { flower.row - 1, flower.col, flower.day + 1 },
            { flower.row, flower.col - 1, flower.day + 1 },
            { flower.row + 1, flower.col, flower.day + 1 },
            { flower.row, flower.col + 1, flower.day + 1 }
        };

        for (int i = 0; i < 4; i++) {
            Flower adj = adjacents[i];

            if (!is_in_range(adj.row, 0, n) || !is_in_range(adj.col, 0, n) || garden[adj.row][adj.col] == 1) {
                continue;
            }

            garden[adj.row][adj.col] = 1;

            if (answer < adj.day) {
                answer = adj.day;
            }

            queue[queue_tail] = adj;
            queue_tail++;
        }

        queue_head++;
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int n1 = 3;
    int garden1[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ret1 = solution(n1, garden1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);
    
    int n2 = 2;
    int garden2[2][2] = {{1, 1}, {1, 1}};
    int ret2 = solution(n2, garden2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
}