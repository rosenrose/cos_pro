// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void permutations_recursive(vector<int>& card, int depth, vector<bool>& visited_idx, vector<int>& selected, vector<int>& numbers) {
    if (depth == card.size()) {
        int number = 0;

        for (int exp = 0; exp < card.size(); exp++) {
            number += selected[card.size() - 1 - exp] * pow(10, exp);
        }

        numbers.push_back(number);
        return;
    }

    bool visited_num[10] = { false, };

    for (int i = 0; i < card.size(); i++) {
        int num = card[i];

        if (visited_num[num] || visited_idx[i]) {
            continue;
        }

        visited_num[num] = true;
        visited_idx[i] = true;

        selected[depth] = num;
        permutations_recursive(card, depth + 1, visited_idx, selected, numbers);

        visited_idx[i] = false;
    }
}

vector<int> permutations(vector<int>& card) {
    int depth = 0;
    vector<bool> visited_idx(card.size());
    vector<int> selected(card.size());
    vector<int> numbers;

    permutations_recursive(card, depth, visited_idx, selected, numbers);

    return numbers;
}

int solution(vector<int> card, int n) {
    sort(card.begin(), card.end());
    vector<int> numbers = permutations(card);

    auto it = find(numbers.begin(), numbers.end(), n);
    int answer = (it == numbers.end()) ? -1 : it - numbers.begin() + 1;

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<int> card1 = {1, 2, 1, 3};
    int n1 = 1312;
    int ret1 = solution(card1, n1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    vector<int> card2 = {1, 1, 1, 2};
    int n2 = 1122;
    int ret2 = solution(card2, n2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}