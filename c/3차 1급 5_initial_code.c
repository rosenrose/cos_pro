// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define DISPLAY_LEN 14

char* substr(char* src, int idx, int len) {
    char* dst = (char*)calloc(sizeof(char), len + 1);
    strncpy(dst, src + idx, len);
    dst[len] = 0;

    return dst;
}

char* solution(char* phrases, int second) {
    int second_passed = second % (DISPLAY_LEN * 2);
    char* answer = (char*)calloc(sizeof(char), DISPLAY_LEN + 1);

    if (second_passed <= DISPLAY_LEN) {
        int phrase_start_idx = DISPLAY_LEN - second_passed;
        int visible_phrase_len = second_passed;

        for (int i = 0; i < phrase_start_idx; i++) {
            answer[i] = '_';
        }

        strncpy(answer + phrase_start_idx, phrases, visible_phrase_len);
    } else {
        int phrase_start_idx = second_passed - DISPLAY_LEN;
        int visible_phrase_len = strlen(phrases) - phrase_start_idx;

        strncpy(answer, phrases + phrase_start_idx, visible_phrase_len);

        for (int i = visible_phrase_len; i < DISPLAY_LEN; i++) {
            answer[i] = '_';
        }
    }

    answer[DISPLAY_LEN] = 0;
    
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    char* phrases = "happy-birthday";
    int second = 3;
    char* ret = solution(phrases, second);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %s 입니다.\n", ret);
}