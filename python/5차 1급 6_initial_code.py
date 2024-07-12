#다음과 같이 import를 사용할 수 있습니다.
#import math

def calc_num(number, radix):
    return sum([int(digit) * (radix ** exp) for exp, digit in enumerate(number[::-1])])

def solution(s1, s2, p, q):
    answer = ''
    num = calc_num(s1, p) + calc_num(s2, p)

    while num > 0:
        answer += str(num % q)
        num //= q

    answer = answer[::-1]

    return answer

#아래는 테스트케이스 출력을 해보기 위한 코드입니다.
s1 = "112001"
s2 = "12010"
p = 3
q = 8
ret = solution(s1, s2, p, q)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret, "입니다.")