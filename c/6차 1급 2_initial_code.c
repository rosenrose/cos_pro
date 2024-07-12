// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int K, char* words[], int words_len) {
    int answer = 1;
    int length = 0;

    for (int i = 0; i < words_len; i++) {
        int word_len = strlen(words[i]);

        if (length + word_len <= K) {
            length += word_len;
        } else {
            length = word_len;
            answer++;
        }

        if (i == words_len - 1) {
            continue;
        }

        if (length + 1 <= K) {
            length += 1;
        } else {
            length = 0;
            answer++;
        }
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int K = 10;
    char* words[] = {"nice", "happy", "hello", "world", "hi"};
    int words_len = 5;
    int ret = solution(K, words, words_len);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}