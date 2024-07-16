#다음과 같이 import를 사용할 수 있습니다.
#import math

def solution(K, words):
    answer = 1
    length = 0

    for i, word in enumerate(words):
        word_len = len(word)

        if length + word_len <= K:
            length += word_len
        else:
            length = word_len
            answer += 1

        if i == len(words) - 1:
            continue

        if length + 1 <= K:
            length += 1
        else:
            length = 0
            answer += 1

    return answer

#아래는 테스트케이스 출력을 해보기 위한 코드입니다.
K = 10
words = ["nice", "happy", "hello", "world", "hi"]
ret = solution(K, words)

#[실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret, "입니다.")