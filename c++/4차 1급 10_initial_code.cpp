// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_prime(int num) {
    for(int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool is_in_range(int num, int lower_include, int upper_exclude) {
    return lower_include <= num && num < upper_exclude;
}

int solution(int a, int b) {
    int answer = 0;

    for (int num = 2; num * num <= b; num++) {
        if (!is_prime(num)) {
            continue;
        }

        if (is_in_range(num * num, a, b + 1)) {
            answer++;
        }
        if (is_in_range(num * num * num, a, b + 1)) {
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
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
   
    return 0;
}