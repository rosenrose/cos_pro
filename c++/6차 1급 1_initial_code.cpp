// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <array>

using namespace std;

struct Flower {
    int row;
    int col;
    int day;
};

bool is_in_range(int num, int lower_include, int upper_exclude) {
    return lower_include <= num && num < upper_exclude;
}

int solution(int n, vector<vector<int>> garden) {
    int answer = 0;
    deque<Flower> queue;

    for (int r = 0; r < garden.size(); r++) {
        for (int c = 0; c < garden[r].size(); c++) {
            if (garden[r][c] == 0) {
                continue;
            }

            Flower flower = { r, c, 0 };
            queue.push_back(flower);
        }
    }

    while(!queue.empty()) {
        Flower flower = queue.front();
		queue.pop_front();
        array<Flower, 4> adjacents = {
            Flower{ flower.row - 1, flower.col, flower.day + 1 },
            Flower{ flower.row, flower.col - 1, flower.day + 1 },
            Flower{ flower.row + 1, flower.col, flower.day + 1 },
            Flower{ flower.row, flower.col + 1, flower.day + 1 }
        };

        for (auto adj : adjacents) {
            if (!is_in_range(adj.row, 0, n) || !is_in_range(adj.col, 0, n) || garden[adj.row][adj.col] == 1) {
                continue;
            }

            garden[adj.row][adj.col] = 1;
            answer = max(adj.day, answer);
            queue.push_back(adj);
        }
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int n1 = 3;
    vector<vector<int>> garden1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ret1 = solution(n1, garden1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    int n2 = 2;
    vector<vector<int>> garden2 = {{1, 1}, {1, 1}};
    int ret2 = solution(n2, garden2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}