// You may use include as below.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long num) {
    string num_as_string = to_string(num + 1);

    for (int i = 0; i < num_as_string.length(); i++) {
        if (num_as_string[i] == '0') {
            num_as_string[i] = '1';
        }
    }

    long long answer = stoll(num_as_string);
    return answer;
}

// The following is main function to output testcase.
int main() {
    long long num = 9949999;
    long long ret = solution(num);

    // Press Run button to receive output. 
    cout << "Solution: return value of the function is " << ret << " ." << endl;
}