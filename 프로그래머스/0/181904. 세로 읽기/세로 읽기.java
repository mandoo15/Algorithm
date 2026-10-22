/*
문자열 my_string
정수 m, c
my_string을 한 줄에 m 글자씩 가로로 적었을 때 왼쪽부터 세로로 c번쨰 열에 적힌 글자들을 문자열로 return

*/
class Solution {
    public String solution(String my_string, int m, int c) {
        String answer = "";
        
        int x = c-1;
        for(int i=0; i<my_string.length()/m; i++){
            answer += Character.toString(my_string.charAt(x));
            x+=m;
        }
        return answer;
    }
}