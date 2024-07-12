// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_NUM 10000

bool is_in_range(int num, int lower_include, int upper_exclude) {
    return lower_include <= num && num < upper_exclude;
}

int solution(int number, int target) {
    int* steps = (int*)calloc(sizeof(int), MAX_NUM + 1);
    int* queue = (int*)calloc(sizeof(int), MAX_NUM + 1);
    int queue_head = 0;
    int queue_tail = 0;

    for (int i = 0; i <= MAX_NUM; i++) {
        steps[i] = -1;
    }

    steps[number] = 0;
    queue[queue_tail] = number;
    queue_tail++;

    while (queue_head <= queue_tail) {
        int num = queue[queue_head];
        int adjacents[3] = { num + 1, num - 1, num * 2 };

        for (int i = 0; i < 3; i++) {
            int adj = adjacents[i];

            if (!is_in_range(adj, 0, MAX_NUM + 1) || steps[adj] != -1) {
                continue;
            }

            steps[adj] = steps[num] + 1;
            queue[queue_tail] = adj;
            queue_tail++;
        }

        queue_head++;
    }

    int answer = steps[target];

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int number1 = 5;
    int target1 = 9;
    int ret1 = solution(number1, target1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

    int number2 = 3;
    int target2 = 11;
    int ret2 = solution(number2, target2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);    
}