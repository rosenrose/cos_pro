# 다음과 같이 import를 사용할 수 있습니다.
# import math

def solution(hour, minute):
    hour_degree = (hour % 12 * 30) + (minute * 0.5)
    minute_degree = minute * 6
    angle = abs(hour_degree - minute_degree)

    angle = min(angle, 360 - angle)
    answer = f"{angle:.1f}"

    return answer

# 아래는 테스트케이스 출력을 해보기 위한 코드입니다.
hour = 3
minute = 0
ret = solution(hour, minute)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은 ", ret, " 입니다.")