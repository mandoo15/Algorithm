// num_list의 홀수만 순서대로 이어 붙인 수와 짝수만 순서대로 이어 붙인 수의 합을 return
class Solution {
    public int solution(int[] num_list) {
        String odd = "", even = "";
        for(int i=0; i<num_list.length; i++){
            if(num_list[i]%2==1){ // 홀수
                odd += Integer.toString(num_list[i]);
            }
            
            if(num_list[i]%2==0) { // 짝수
                even += Integer.toString(num_list[i]);
            }
        }
        int answer = Integer.parseInt(odd) + Integer.parseInt(even);
        return answer;
    }
}