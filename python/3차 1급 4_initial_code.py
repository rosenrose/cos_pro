# 다음과 같이 import를 사용할 수 있습니다.
# import math

def solution(s1, s2):
    s1_len = len(s1)
    s2_len = len(s2)
    common_len = 0

    for length in range(1, min(s1_len, s2_len) + 1):
        s1_prefix = s1[:length]
        s2_suffix = s2[-length:]

        if s1_prefix == s2_suffix:
            common_len = length

        s2_prefix = s2[:length]
        s1_suffix = s1[-length:]

        if s2_prefix == s1_suffix:
            common_len = length

    answer = s1_len + s2_len - common_len

    return answer

# 아래는 테스트케이스 출력을 해보기 위한 코드입니다.
s1 = "ababc"
s2 = "abcdab"
ret = solution(s1, s2)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret, "입니다.")