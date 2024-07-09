// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

char* solution(int hour, int minute) {
    char* answer = (char*)calloc(sizeof(char), 6);
    answer[5] = 0;

    float hour_degree = (hour % 12 * 30) + (minute * 0.5);
    float minute_degree = minute * 6;
    float angle = fabs(hour_degree - minute_degree);

    if (angle > 180) {
        angle = 360 - angle;
    }

    sprintf(answer, "%.1f", angle);

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int hour = 3;
    int minute = 0;
    char* ret = solution(hour, minute);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %s 입니다.\n", ret);
}