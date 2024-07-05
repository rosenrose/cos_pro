// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

char* substr(char* src, int idx, int len) {
    char* dst = (char*)calloc(sizeof(char), len + 1);
    strncpy(dst, src + idx, len);
    dst[len] = 0;

    return dst;
}

int solution(char* s1, char* s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int common_length = 0;

    for (int len = 1; len <= min(s1_len, s2_len); len++) {
        char* s1_prefix = substr(s1, 0, len);
        char* s2_suffix = substr(s2, s2_len - len, len);

        if (strcmp(s1_prefix, s2_suffix) == 0) {
            common_length = len;
        }

        char* s2_prefix = substr(s2, 0, len);
        char* s1_suffix = substr(s1, s1_len - len, len);

        if (strcmp(s2_prefix, s1_suffix) == 0) {
            common_length = len;
        }
    }

    int answer = s1_len + s2_len - common_length;

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    char* s1 = "ababc";
    char* s2 = "abcdab";
    int ret = solution(s1, s2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}