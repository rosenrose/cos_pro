// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

const int MAX_LEN = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2;

void permutations_resursive(int card[], int card_len, int depth, bool visited_idx[], int* selected, int* numbers, int* count) {
    if (depth == card_len) {
        int number = 0;

        for (int exp = 0; exp < card_len; exp++) {
            number += selected[card_len - exp - 1] * pow(10, exp);
        }

        numbers[*count] = number;
        (*count)++;

        return;
    }

    bool visited_num[10] = { false, };

    for (int i = 0; i < card_len; i++) {
        int num = card[i];

        if (visited_num[num] || visited_idx[i]) {
            continue;
        }

        visited_num[num] = true;
        visited_idx[i] = true;

        selected[depth] = num;
        permutations_resursive(card, card_len, depth + 1, visited_idx, selected, numbers, count);

        visited_idx[i] = false;
    }
}

int* permutations(int card[], int card_len, int* count) {
    int depth = 0;
    bool visited_idx[9] = { false, };
    int* selected = (int*)calloc(sizeof(int), card_len);
    int* numbers = (int*)calloc(sizeof(int), MAX_LEN);

    permutations_resursive(card, card_len, depth, visited_idx, selected, numbers, count);

    return numbers;
}

int compare(const void *a, const void * b){
    int first = *(int *)a;
    int second = *(int *)b;

    return (first < second) ? -1 : (first > second) ? 1 : 0;
}

int solution(int card[], int card_len, int n) {
    qsort(card, card_len, sizeof(int), compare);
    int count = 0;
    int* numbers = permutations(card, card_len, &count);

    // for (int i = 0; i < count; i++) {
    //     printf("%d, ", numbers[i]);
    // }
    // printf("\n");

    for (int answer = 0; answer < count; answer++) {
        if (numbers[answer] == n) {
            return answer + 1;
        }
    }

    return -1;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int card1[] = {1, 2, 1, 3};
    int card_len1 = 4;
    int n1 = 1312;
    int ret1 = solution(card1, card_len1, n1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

    int card2[] = {1, 1, 1, 2};
    int card_len2 = 4;
    int n2 = 1122;
    int ret2 = solution(card2, card_len2, n2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
}