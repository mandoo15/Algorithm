/*
1을 만들기 위해서 필요한 나누기 연산의 횟수
짝수라면? n/2
홀수라면? (n-1)/2
*/
class Solution {
    public int solution(int[] num_list) {
        int answer = 0, n = num_list[0];
        for(int i=0; i<num_list.length; i++){
            n = num_list[i];
            while(n>1){
                if(n%2==0){
                    n /= 2;
                    answer++;
                    if(n==1) break;
                }
                if(n%2==1){
                    n = (n-1)/2;
                    answer++;
                    if(n==1) break;
                }
            }
        }
        return answer;
    }
}