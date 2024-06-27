// You may use include as below.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long num) {
    char num_as_string[20] = { 0 };

    sprintf(num_as_string, "%lld", num + 1);

    for (int i = 0; i < sizeof(num_as_string); i++) {
        if (num_as_string[i] == '0') {
            num_as_string[i] = '1';
        }
    }

    long long answer = atoll(num_as_string);

    return answer;
}

// The following is main function to output testcase.
int main() {
    long long num = 9949999;
    long long ret = solution(num);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %lld .\n", ret);
}