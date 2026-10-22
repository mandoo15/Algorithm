class Solution {
    public int solution(int left, int right) {
        int answer = 0, sum = 0;
        for(int i=left; i<right+1; i++){
            for(int j=1; j<i+1; j++){
                if(i%j==0) sum++;
            }
            if(sum%2==0) answer += i;
            if(sum%2==1) answer -= i;
            sum=0;
        }
        return answer;
    }
}