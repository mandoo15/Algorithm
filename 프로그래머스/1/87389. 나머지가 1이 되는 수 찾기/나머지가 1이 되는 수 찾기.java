// n을 x로 나눈 나머지가 1이 되게 하는 가장 작은 자연수 x
class Solution {
    public int solution(int n) {
        int answer = 0;
        for(int i=2; i<n; i++){
            if(n%i==1) {
                answer = i;
                break;
            }
        }
        return answer;
    }
}