#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Point2D {
    int x;
    int y;
}Point2D;

typedef struct Rectangle{
    Point2D* LeftDown;
    Point2D* RightUp;
}Rectangle;

int solution(int x1, int y1, int x2, int y2, int plus_x, int plus_y){
    Point2D leftdown = { x1, y1 };
    Point2D rightup = { x2, y2 };
    Rectangle rect = { &leftdown, &rightup };
    
    int first_area = (rect.RightUp->x - rect.LeftDown->x) * (rect.RightUp->y - rect.LeftDown->y);
    
    rightup.x += plus_x;
    rightup.y += plus_y;
    
    int second_area = (rect.RightUp->x - rect.LeftDown->x) * (rect.RightUp->y - rect.LeftDown->y);
    
    return second_area - first_area;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int ret = solution(1, 1, 5, 5, 2, 1);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
}