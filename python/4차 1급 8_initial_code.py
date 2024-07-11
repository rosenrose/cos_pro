# 다음과 같이 import를 사용할 수 있습니다.
# import math

def permutations_recursive(card, depth, visited_idx, selected, numbers):
    if depth == len(card):
        number = sum([digit * (10 ** exp) for exp, digit in enumerate(selected[::-1])])
        numbers.append(number)
        return

    visited_num = [False] * 10

    for i, num in enumerate(card):
        if visited_num[num] or visited_idx[i]:
            continue

        visited_num[num] = True
        visited_idx[i] = True

        selected[depth] = num
        permutations_recursive(card, depth + 1, visited_idx, selected, numbers)

        visited_idx[i] = False
        

def permutations(card):
    depth = 0
    visited_idx = [False] * len(card)
    selected = [0] * len(card)
    numbers = []

    permutations_recursive(card, depth, visited_idx, selected, numbers)

    return numbers

def solution(card, n):
    card.sort()
    numbers = permutations(card)

    try:
        answer = numbers.index(n) + 1
    except ValueError:
        answer = -1
    
    return answer

# 아래는 테스트케이스 출력을 해보기 위한 코드입니다.
card1 = [1, 2, 1, 3]
n1 = 1312
ret1 = solution(card1, n1)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은 ", ret1, " 입니다.")

# 아래는 테스트케이스 출력을 해보기 위한 코드입니다.
card2 = [1, 1, 1, 2]
n2 = 1122
ret2 = solution(card2, n2)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은 ", ret2, " 입니다.")