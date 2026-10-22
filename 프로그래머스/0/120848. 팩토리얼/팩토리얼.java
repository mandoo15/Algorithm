class Solution {
    public int solution(int n) {
        int answer = 0;
        int x = 0, sum = 1;
        while(true){
            x++; sum = 1;
            for(int i=1; i<x+1; i++){
                sum *= i;
            }
            if(sum > n) break;
        }
        answer = x-1;
        return answer;
    }
}