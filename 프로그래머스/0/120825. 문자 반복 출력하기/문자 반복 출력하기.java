/*
s와 n이 매개변수
s에 들어있는 문자를 n만큼 반복한 문자열 return
-> 이중for문
*/
class Solution {
    public String solution(String s, int n) {
        //String[] arrs = s.split(""); // 문자열 s를 각 문자로 나눠서 배열에 삽입
        String answer = ""; // 문자열 배열 answer 생성
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<n; j++){
                answer += s.charAt(i);
            }
        }
        return answer;
    }
}