// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int K, vector<string> words) {
    int answer = 1;
    int length = 0;

    for (int i = 0; i < words.size(); i++) {
        int word_len = words[i].length();

        if (length + word_len <= K) {
            length += word_len;
        } else {
            length = word_len;
            answer++;
        }

        if (i == words.size() - 1) {
            continue;
        }

        if (length + 1 <= K) {
            length += 1;
        } else {
            length = 0;
            answer++;
        }
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int K = 10;
    vector<string> words = {"nice", "happy", "hello", "world", "hi"};
    int ret = solution(K, words);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다.";
}