#다음과 같이 import를 사용할 수 있습니다.
#import math

def solution(arr, K):
    arr_len = len(arr)
    answer = 0

    for a in range(0, arr_len - 2):
        for b in range(a + 1, arr_len - 1):
            for c in range(b + 1, arr_len):
                if (arr[a] + arr[b] + arr[c]) % K != 0:
                    continue

                answer += 1

    return answer

#아래는 테스트케이스 출력을 해보기 위한 코드입니다.
arr = [1, 2, 3, 4, 5]
K = 3
ret = solution(arr, K)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은 ", ret, " 입니다.")