#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*(n/2)); // n 크기만큼 할당.
    int x = 0;
    for(int i=1; i<n+1; i=i+2){
        answer[x] = i;
        x+=1;
    }
    return answer;
}