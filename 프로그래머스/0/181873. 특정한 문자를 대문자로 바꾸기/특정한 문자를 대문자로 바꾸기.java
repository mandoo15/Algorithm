/*
영소문자로 이루어진 문자열 my_string과 
영소문자 1글자로 이루어진 문자열 alp가 매개변수

my_string에서 alp에 해당하는 모든 글자를 대문자로 바꾼 문자열 return

-> HOW?
replace 사용
*/
class Solution {
    public String solution(String my_string, String alp) {
        String answer = "";
        char ch = alp.charAt(0);
        int sum = (int)(ch)-32;
        String Up = Character.toString((char)(sum));
        answer = my_string.replace(alp, Up);
        return answer;
    }
}