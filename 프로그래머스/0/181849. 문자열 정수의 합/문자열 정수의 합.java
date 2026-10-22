/*
한 자리 정수로 이루어진 문자열 num_str
각 자리수의 합을 return
-> HOW?
for문 사용해서 charAt(i) <- int로 변경
더하기
*/
class Solution {
    public int solution(String num_str) {
        int answer = 0;
        for(int i=0; i<num_str.length(); i++){
            String x = Character.toString(num_str.charAt(i));
            answer += Integer.parseInt(x);
        }
        return answer;
    }
}