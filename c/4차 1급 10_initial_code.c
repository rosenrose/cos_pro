// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool is_in_range(int num, int lowerInclude, int upperExclude) {
    return lowerInclude <= num && num < upperExclude;
}

int solution(int a, int b) { 
    int answer = 0;

    for (int i = 2; i * i <= b; i++) {
        if (!is_prime(i)) {
            continue;
        }

        if (is_in_range(i * i, a, b + 1)) {
            answer++;
        }
        
        if (is_in_range(i * i * i, a, b + 1)) {
            answer++;
        }
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int a = 6;
    int b = 30;
    int ret = solution(a, b);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}