// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calc_num(string number, int radix) {
    int num = 0;
    int pow = 1;

    for (int i = number.length() - 1; i >= 0; i--) {
        num += (number[i] - '0') * pow;
        pow *= radix;
    }

    return num;
}

string solution(string s1, string s2, int p, int q) {
    string answer = "";
    int num = calc_num(s1, p) + calc_num(s2, p);

    while (num > 0) {
        answer += to_string(num % q);
        num /= q;
    }

    reverse(answer.begin(), answer.end());
    
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    string s1 = "112001";
    string s2 = "12010";
    int p = 3;
    int q = 8;
    string ret = solution(s1, s2, p, q);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}