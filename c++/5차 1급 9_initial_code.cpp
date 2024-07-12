// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <deque>
#include <array>

using namespace std;
const int MAX_NUM = 10000;

bool is_in_range(int num, int lower_include, int upper_exclude) {
    return lower_include <= num && num < upper_exclude;
}

int solution(int number, int target) {
	array<int, MAX_NUM + 1> steps;
	deque<int> queue = { number };

	steps.fill(-1);
	steps[number] = 0;

	while (!queue.empty()) {
		int num = queue.front();
		queue.pop_front();
		array<int, 3> adjacents = { num + 1, num - 1, num * 2 };

		for (auto adj : adjacents) {
			if (!is_in_range(adj, 0, MAX_NUM + 1) || steps[adj] != -1) {
				continue;
			}

			steps[adj] = steps[num] + 1;
			queue.push_back(adj);
		}
	}

	int answer = steps[target];

	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int number1 = 5;
	int target1 = 9;
	int ret1 = solution(number1, target1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int number2 = 3;
	int target2 = 11;
	int ret2 = solution(number2, target2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}