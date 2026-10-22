#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n); //3
    for(int i=1; i<n+1; i++){ //3 012
        for(int j=0; j<i; j++){ // 0 | 01 | 012
            printf("*");
        }
        printf("\n");
    }
    return 0;
}