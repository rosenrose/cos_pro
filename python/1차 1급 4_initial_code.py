#You may use import as below.
#import math

def solution(num):
    num_as_string = str(num + 1)
    answer = int(num_as_string.replace("0", "1"))

    return answer


#The following is code to output testcase.
num = 9949999
ret = solution(num)

#Press Run button to receive output. 
print("Solution: return value of the function is", ret, ".")