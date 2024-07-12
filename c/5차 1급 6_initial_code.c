// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calc_num(char* number, int radix) {
    int num = 0;
    int pow = 1;

    for (int i = strlen(number) - 1; i >= 0; i--) {
        num += (number[i] - '0') * pow;
        pow *= radix;
    }

    return num;
}

char* solution(char* s1, char* s2, int p, int q) {
    char* answer = (char*)calloc(sizeof(char), 11);
    answer[10] = 0;

    int num = calc_num(s1, p) + calc_num(s2, p);
    int i = 0;

    for (; num > 0; num /= q) {
        answer[i] = (num % q) + '0';
        i++;
    }

    answer[i] = 0;
    i--;
    int answer_len = strlen(answer);

    for (; i >= answer_len / 2; i--) {
        int temp = answer[i];
        answer[i] = answer[answer_len - i - 1];
        answer[answer_len - i - 1] = temp;
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    char* s1 = "112001";
    char* s2 = "12010";
    int p = 3;
    int q = 8;
    char* ret = solution(s1, s2, p, q);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %s 입니다.\n", ret);
}