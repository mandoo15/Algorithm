#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int k) { // n은 양꼬치 k는 음료수 양꼬치 10 -> 음료수 1 서비스
    int answer = 0;
    if(n > 10 ){
        answer = (k - n/10)*2000 + n*12000;
    }
    else answer = k*2000 + n*12000;
    return answer;
}