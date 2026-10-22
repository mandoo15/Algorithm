/*
정수 리스트 num_list와 찾으려는 정수 n이 주어질 때,
num_list 안에 n이 있으면 1 없으면 0 return
-> HOW?
정수를 string으로 만들어 contains함수 사용.
*/
class Solution {
    public int solution(int[] num_list, int n) {
        int answer = 0;
        
        for(int i=0; i<num_list.length; i++){
            if(num_list[i] == n) answer = 1;
        }
        return answer;
    }
}