// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solution(int arr[], int arr_len) {
    int answer = 1;

    for (int start = 0, end = 1; end < arr_len; end++) {
        if (arr[end - 1] < arr[end]) {
            answer = max(end - start + 1, answer);
        } else {
            start = end;
        }
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int arr[10] = {3, 1, 2, 4, 5, 1, 2, 2, 3, 4};
    int arr_len = 10;
    int ret = solution(arr, arr_len);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}