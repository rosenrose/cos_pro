#다음과 같이 import를 사용할 수 있습니다.
#import math

def is_prime(num):
    i = 2

    while i * i <= num:
        if num % i == 0:
            return False

        i += 1

    return True

def solution(a, b):
    answer = 0
    num = 2

    while num * num <= b:
        if is_prime(num):
            if num ** 2 in range(a, b + 1):
                answer += 1

            if num ** 3 in range(a, b + 1):
                answer += 1

        num += 1

    return answer

#아래는 테스트케이스 출력을 해보기 위한 코드입니다.
a =  6
b =  30
ret = solution(a, b)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret, "입니다.")