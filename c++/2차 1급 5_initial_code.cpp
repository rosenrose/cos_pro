// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;

    for (int start = 0, end = 1; end < arr.size(); end++) {
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
    vector<int> arr = {3, 1, 2, 4, 5, 1, 2, 2, 3, 4};
    int ret = solution(arr);


    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}