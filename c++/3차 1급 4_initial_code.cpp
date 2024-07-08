// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s1, string s2) {
    int s1_len = s1.length();
    int s2_len = s2.length();
    int common_length = 0;

    for (int len = 1; len <= min(s1_len, s2_len); len++) {
        string s1_prefix = s1.substr(0, len);
        string s2_suffix = s2.substr(s2_len - len, len);

        if (s1_prefix.compare(s2_suffix) == 0) {
            common_length = len;
        }

        string s2_prefix = s2.substr(0, len);
        string s1_suffix = s1.substr(s1_len - len, len);

        if (s2_prefix.compare(s1_suffix) == 0) {
            common_length = len;
        }
    }

    int answer = s1_len + s2_len - common_length;

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    string s1 = "ababc";
    string s2 = "abcdab";
    int ret = solution(s1, s2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}