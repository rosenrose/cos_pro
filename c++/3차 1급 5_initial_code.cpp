// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <format>

using namespace std;

string solution(string phrases, int second) {
    string placeholder = "______________";
    string total_text = format("{0}{1}{0}", placeholder, phrases);

    string answer = total_text.substr(second % 28, placeholder.length());

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    string phrases = "happy-birthday";
    int second = 3;
    string ret = solution(phrases, second);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}