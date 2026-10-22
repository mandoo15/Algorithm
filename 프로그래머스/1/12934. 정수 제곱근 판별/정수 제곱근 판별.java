class Solution {
    public long solution(long n) { // long형
        long x = 1; 
        long answer = 0;
        for(long j = 0; j<n; j++){ // 숫자 n만큼 반복
            if(n == x*x) { // n이 어떤 수 x의 제곱이면
                answer = (x+1)*(x+1); // answer값은 x+1의 제곱이다.
                break;
            }
            x++;
        }
        if(answer == 0) answer = -1;
        // answer가 여전히 0이라면 ( == 어떤 수 x의 제곱이 될 수 없었음을 의미)
        // answer = -1이다.
        return answer;
    }
}