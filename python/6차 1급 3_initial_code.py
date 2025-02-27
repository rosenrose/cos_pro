#다음과 같이 import를 사용할 수 있습니다.
#import math

def solution(arr, K):
    arr.sort()
    answer = 10000

    for i, num1 in enumerate(arr[:-K + 1]):
        for num2 in arr[i + K - 1:]:
            diff = abs(num1 - num2)
            answer = min(diff, answer)

    return answer

#아래는 테스트케이스 출력을 해보기 위한 코드입니다.
arr = [9, 11, 9, 6, 4, 19]
K = 4
ret = solution(arr, K)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret, "입니다.")