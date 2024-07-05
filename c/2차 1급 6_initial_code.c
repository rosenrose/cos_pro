// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(char* commands) {
    int* answer = (int*)calloc(sizeof(int), 2);
    int x = 0;
    int y = 0;

    for (int i = 0; i < strlen(commands); i++) {
        switch (commands[i]) {
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
        }
    };

    answer[0] = x;
    answer[1] = y;

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    char* commands = "URDDL";
    int* ret = solution(commands);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 {");
    for(int i = 0; i < 2; i++){
        if (i != 0) printf(", ");
        printf("%d", ret[i]);
    }
    printf("} 입니다.\n");
}