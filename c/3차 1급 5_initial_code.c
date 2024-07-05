// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(char* phrases, int second) {
    char* placeholder = "______________";
    int placeholder_len = strlen(placeholder);
    int total_text_len = placeholder_len * 2 + strlen(phrases);

    char* total_text = (char*)calloc(sizeof(char), total_text_len + 1);
    char* answer = (char*)calloc(sizeof(char), placeholder_len + 1);

    sprintf(total_text, "%s%s%s", placeholder, phrases, placeholder);
    strncpy(answer, total_text + (second % 28), placeholder_len);

    total_text[total_text_len] = 0;
    answer[placeholder_len] = 0;

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