// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <format>

using namespace std;

string solution(int hour, int minute) {
    float hour_degree = (hour % 12 * 30) + (minute * 0.5);
    float minute_degree = minute * 6;
    float angle = abs(hour_degree - minute_degree);

    if (angle > 180) {
        angle = 360 - angle;
    }

    string answer = format("{:.1f}", angle);
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int hour = 3;
    int minute = 0;
    string ret = solution(hour, minute);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}