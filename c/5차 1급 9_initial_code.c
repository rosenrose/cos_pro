// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_NUM 10000

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solution(int number, int target) {
    int* steps = (int*)calloc(sizeof(int), MAX_NUM * 2 + 1);

    for (int i = number; i <= MAX_NUM * 2; i++) {
        steps[i] = i - number;
    }
    for (int i = number; i >= 0; i--) {
        steps[i] = number - i;
    }

    for (int i = 1; i <= MAX_NUM; i++) {
        int step = 0;

        for (int j = i; j <= MAX_NUM * 2; j *= 2) {
            steps[j] = min(steps[j], steps[i] + step);
            step++;
        }
    }

    for (int i = 2; i <= MAX_NUM * 2; i += 2) {
        for (int j = i; j <= MAX_NUM * 2; j++) {
            steps[j] = min(steps[j], steps[i] + (j - i));
        }
        for (int j = i; j >= 0; j--) {
            steps[j] = min(steps[j], steps[i] + (i - j));
        }
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